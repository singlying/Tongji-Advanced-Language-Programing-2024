
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <ctime>
#include "magic_ball.h"
#include "cmd_console_tools.h"
using namespace std;

// 生成内部数组
void init_matirx(Matrix& matrix)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < matrix.row; i++) {
		for (int j = 0; j < matrix.column; j++) {
			matrix.arr[i][j].data = rand() % 9 + 1;
		}
	}
}

bool test_triple(Matrix& matrix)
{
	reset_matrix(matrix);  //默认首先重置状态

	bool tag = false;
	for (int i = 0; i < matrix.row; i++) {  //横向检查
		int count = 0, last = 0;
		for (int j = 0; j < matrix.column; j++) {
			if (last == matrix.arr[i][j].data)
				count++;
			else
				count = 1;
			last = matrix.arr[i][j].data;
			if (count >= 3) {
				matrix.arr[i][j].is_triple = true;
				matrix.arr[i][j - 1].is_triple = true;
				matrix.arr[i][j - 2].is_triple = true;
				tag = true;
			}
		}
	}


	for (int i = 0; i < matrix.column; i++) {  //横向检查
		int count = 0, last = 0;
		for (int j = 0; j < matrix.row; j++) {
			if (last == matrix.arr[j][i].data)
				count++;
			else
				count = 1;
			last = matrix.arr[j][i].data;
			if (count >= 3) {
				matrix.arr[j][i].is_triple = true;
				matrix.arr[j - 1][i].is_triple = true;
				matrix.arr[j - 2][i].is_triple = true;
				tag = true;
			}
		}
	}

	return tag;
}

void drop_ball(Matrix& matrix)
{
	for (int i = 0; i < matrix.column; i++) {
		int count = 0;  //下落次数
		for (int j = 0; j < matrix.row; j++) {
			if (matrix.arr[j][i].is_triple) {  //如果需要下落
				for (int u = j; u > 0; u--) {
					matrix.arr[u][i] = matrix.arr[u - 1][i];  //这样写下面的is_triple均为false
				}
				count++;
			}
		}

		for (int j = 0; j < count; j++) {  //下落的球赋值0
			matrix.arr[j][i].data = 0;
			matrix.arr[j][i].is_triple = true;
		}
	}
}

int refill_matrix(Matrix& matrix)
{
	int score = 0;
	for (int i = 0; i < matrix.column; i++) {
		for (int j = 0; j < matrix.row; j++) {
			if (matrix.arr[i][j].data == 0) {
				matrix.arr[i][j].data = rand() % 9 + 1;
				score++;
			}
		}
	}
	return score;
}

bool detect_elimination(Matrix& matrix)
{
	reset_matrix(matrix);  //重置状态

	bool tag = false;
	for (int i = 0; i < matrix.row; i++) {
		for (int j = 0; j < matrix.column; j++) {
			int up = i > 0 ? matrix.arr[i - 1][j].data : -1;
			int down = i < matrix.row - 1 ? matrix.arr[i + 1][j].data : -2;
			int left = j > 0 ? matrix.arr[i][j - 1].data : -3;
			int right = j < matrix.column - 1 ? matrix.arr[i][j + 1].data : -4;
			bool* middle = &matrix.arr[i][j].is_triple;  //指向当前节点的is_triple变量

			// 检测中间元
			if (up == down) {  // 上下相同
				if (up == left)  //上下 左
					*middle = matrix.arr[i][j - 1].is_triple = true;
				if (up == right) //上下 右
					*middle = matrix.arr[i][j + 1].is_triple = true;
			}
			if (left == right) { //左右相同
				if (i > 0 && left == up) //左右 上
					*middle = matrix.arr[i - 1][j].is_triple = true;
				if (left == down) //左右 下
					*middle = matrix.arr[i + 1][j].is_triple = true;
			}

			//检测两边元
			if (j > 1 && left == matrix.arr[i][j - 2].data) {  //左边两个相等
				if (left == up)  //左边和上边相等
					*middle = matrix.arr[i - 1][j].is_triple = true;
				if (left == right) //左边和右边相等
					*middle = matrix.arr[i][j + 1].is_triple = true;
				if (left == down) //左边和下边相等
					*middle = matrix.arr[i + 1][j].is_triple = true;
			}
			if (j < matrix.column - 2 && right == matrix.arr[i][j + 2].data) { //右边两个相等
				if (right == up) //右边和上边相等
					*middle = matrix.arr[i - 1][j].is_triple = true;
				if (right == left) //右边和左边相等
					*middle = matrix.arr[i][j - 1].is_triple = true;
				if (right == down) //右边和下边相等
					*middle = matrix.arr[i + 1][j].is_triple = true;
			}
			if (i > 1 && up == matrix.arr[i - 2][j].data) {  //上边两个相等
				if (up == left) //上边和左边相等
					*middle = matrix.arr[i][j - 1].is_triple = true;
				if (up == down) //上边和下边相等
					*middle = matrix.arr[i + 1][j].is_triple = true;
				if (up == right) //上边和右边相等
					*middle = matrix.arr[i][j + 1].is_triple = true;
			}
			if (i < matrix.row - 2 && down == matrix.arr[i + 2][j].data) { //下边两个相等
				if (down == left)  //下边和左边相等
					*middle = matrix.arr[i][j - 1].is_triple = true;
				if (down == up)  //下边和上边相等
					*middle = matrix.arr[i - 1][j].is_triple = true;
				if (down == right)  //下边和右边相等
					*middle = matrix.arr[i][j + 1].is_triple = true;
			}

			if (*middle)
				tag = true;
		}
	}
	return tag;
}

void exchange_2ball(node* node1, node* node2)
{
	node temp = *node1;
	*node1 = *node2;
	*node2 = temp;
}

bool test_exchange(Matrix& matrix, node* node1, node* node2)
{
	exchange_2ball(node1, node2);
	bool result = false;
	int i, j, data;
	node* node_arr[2] = { node1, node2 };
	//对node1检查
	for (int u = 0; u < 2; u++) {  // 重复两边检查两个球
		i = (node_arr[u] - matrix.arr[0]) / MAXCOLUMN; //行
		j = (node_arr[u] - matrix.arr[0]) % MAXCOLUMN; //列
		data = matrix.arr[i][j].data;

		if (i > 0 && i < matrix.row - 1) {
			if (matrix.arr[i - 1][j].data == data && data == matrix.arr[i + 1][j].data)  //上下
				result = true;
		}

		if (j > 0 && j < matrix.column - 1) {
			if (matrix.arr[i][j - 1].data == data && data == matrix.arr[i][j + 1].data)  //左右
				result = true;
		}

		if (i > 1 && data == matrix.arr[i - 1][j].data && data == matrix.arr[i - 2][j].data)  //上面两个相同
			result = true;

		if (i < matrix.row - 2 && data == matrix.arr[i + 1][j].data && data == matrix.arr[i + 2][j].data) //下面两个
			result = true;

		if (j > 1 && data == matrix.arr[i][j - 1].data && data == matrix.arr[i][j - 2].data)  //左边两个相同
			result = true;

		if (j < matrix.column - 2 && data == matrix.arr[i][j + 1].data && data == matrix.arr[i][j + 2].data) //右边两个
			result = true;
	}

	exchange_2ball(node1, node2);
	return result;
}

void print_matrix(const Matrix& matrix)
{
	cout << "  |"; //第一行
	for (int i = 0; i < matrix.column; i++)
		cout << "  " << i + 1;

	cout << endl << "--+";  //第二行
	for (int i = 0; i < matrix.column; i++)
		cout << "---";
	cout << endl;

	for (int i = 0; i < matrix.row; i++) {  //第n行
		cout << char('A' + i) << " |";
		for (int j = 0; j < matrix.column; j++) {
			cout << "  ";
			if (!matrix.arr[i][j].is_triple)
				cout << matrix.arr[i][j].data;
			else {
				cct_setcolor(COLOR_HYELLOW, COLOR_HBLUE);
				cout << matrix.arr[i][j].data;
				cct_setcolor();
			}
		}
		cout << endl;
	}
	cout << endl;
}

void reset_matrix(Matrix& matrix)
{
	for (int i = 0; i < matrix.row; i++) {
		for (int j = 0; j < matrix.column; j++) {
			matrix.arr[i][j].is_triple = false;
		}
	}
}