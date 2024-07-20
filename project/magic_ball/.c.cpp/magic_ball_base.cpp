
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <ctime>
#include "magic_ball.h"
#include "cmd_console_tools.h"
using namespace std;

// �����ڲ�����
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
	reset_matrix(matrix);  //Ĭ����������״̬

	bool tag = false;
	for (int i = 0; i < matrix.row; i++) {  //������
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


	for (int i = 0; i < matrix.column; i++) {  //������
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
		int count = 0;  //�������
		for (int j = 0; j < matrix.row; j++) {
			if (matrix.arr[j][i].is_triple) {  //�����Ҫ����
				for (int u = j; u > 0; u--) {
					matrix.arr[u][i] = matrix.arr[u - 1][i];  //����д�����is_triple��Ϊfalse
				}
				count++;
			}
		}

		for (int j = 0; j < count; j++) {  //�������ֵ0
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
	reset_matrix(matrix);  //����״̬

	bool tag = false;
	for (int i = 0; i < matrix.row; i++) {
		for (int j = 0; j < matrix.column; j++) {
			int up = i > 0 ? matrix.arr[i - 1][j].data : -1;
			int down = i < matrix.row - 1 ? matrix.arr[i + 1][j].data : -2;
			int left = j > 0 ? matrix.arr[i][j - 1].data : -3;
			int right = j < matrix.column - 1 ? matrix.arr[i][j + 1].data : -4;
			bool* middle = &matrix.arr[i][j].is_triple;  //ָ��ǰ�ڵ��is_triple����

			// ����м�Ԫ
			if (up == down) {  // ������ͬ
				if (up == left)  //���� ��
					*middle = matrix.arr[i][j - 1].is_triple = true;
				if (up == right) //���� ��
					*middle = matrix.arr[i][j + 1].is_triple = true;
			}
			if (left == right) { //������ͬ
				if (i > 0 && left == up) //���� ��
					*middle = matrix.arr[i - 1][j].is_triple = true;
				if (left == down) //���� ��
					*middle = matrix.arr[i + 1][j].is_triple = true;
			}

			//�������Ԫ
			if (j > 1 && left == matrix.arr[i][j - 2].data) {  //����������
				if (left == up)  //��ߺ��ϱ����
					*middle = matrix.arr[i - 1][j].is_triple = true;
				if (left == right) //��ߺ��ұ����
					*middle = matrix.arr[i][j + 1].is_triple = true;
				if (left == down) //��ߺ��±����
					*middle = matrix.arr[i + 1][j].is_triple = true;
			}
			if (j < matrix.column - 2 && right == matrix.arr[i][j + 2].data) { //�ұ��������
				if (right == up) //�ұߺ��ϱ����
					*middle = matrix.arr[i - 1][j].is_triple = true;
				if (right == left) //�ұߺ�������
					*middle = matrix.arr[i][j - 1].is_triple = true;
				if (right == down) //�ұߺ��±����
					*middle = matrix.arr[i + 1][j].is_triple = true;
			}
			if (i > 1 && up == matrix.arr[i - 2][j].data) {  //�ϱ��������
				if (up == left) //�ϱߺ�������
					*middle = matrix.arr[i][j - 1].is_triple = true;
				if (up == down) //�ϱߺ��±����
					*middle = matrix.arr[i + 1][j].is_triple = true;
				if (up == right) //�ϱߺ��ұ����
					*middle = matrix.arr[i][j + 1].is_triple = true;
			}
			if (i < matrix.row - 2 && down == matrix.arr[i + 2][j].data) { //�±��������
				if (down == left)  //�±ߺ�������
					*middle = matrix.arr[i][j - 1].is_triple = true;
				if (down == up)  //�±ߺ��ϱ����
					*middle = matrix.arr[i - 1][j].is_triple = true;
				if (down == right)  //�±ߺ��ұ����
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
	//��node1���
	for (int u = 0; u < 2; u++) {  // �ظ����߼��������
		i = (node_arr[u] - matrix.arr[0]) / MAXCOLUMN; //��
		j = (node_arr[u] - matrix.arr[0]) % MAXCOLUMN; //��
		data = matrix.arr[i][j].data;

		if (i > 0 && i < matrix.row - 1) {
			if (matrix.arr[i - 1][j].data == data && data == matrix.arr[i + 1][j].data)  //����
				result = true;
		}

		if (j > 0 && j < matrix.column - 1) {
			if (matrix.arr[i][j - 1].data == data && data == matrix.arr[i][j + 1].data)  //����
				result = true;
		}

		if (i > 1 && data == matrix.arr[i - 1][j].data && data == matrix.arr[i - 2][j].data)  //����������ͬ
			result = true;

		if (i < matrix.row - 2 && data == matrix.arr[i + 1][j].data && data == matrix.arr[i + 2][j].data) //��������
			result = true;

		if (j > 1 && data == matrix.arr[i][j - 1].data && data == matrix.arr[i][j - 2].data)  //���������ͬ
			result = true;

		if (j < matrix.column - 2 && data == matrix.arr[i][j + 1].data && data == matrix.arr[i][j + 2].data) //�ұ�����
			result = true;
	}

	exchange_2ball(node1, node2);
	return result;
}

void print_matrix(const Matrix& matrix)
{
	cout << "  |"; //��һ��
	for (int i = 0; i < matrix.column; i++)
		cout << "  " << i + 1;

	cout << endl << "--+";  //�ڶ���
	for (int i = 0; i < matrix.column; i++)
		cout << "---";
	cout << endl;

	for (int i = 0; i < matrix.row; i++) {  //��n��
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