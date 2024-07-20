
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <ctime>
#include "magic_ball.h"
#include "cmd_console_tools.h"
using namespace std;

//〇〇〇 正常的球
//●●● 初始可消除的球
//◎◎◎ 表示可交换的球  有白色 黑色
//¤¤¤ 消除中的效果
// ●-● Hello, I am BAYMAX!


//背景用 HWHITE  前景BLACK

void graph_matrix(const Matrix& matrix, int tag, int delay) //tag = 0不画分割线 1画分割线 delay = 0不延迟 1延迟
{
	//控制延迟时间
	const int DELAY_TIME = delay ? 50 : 0;
	//更改视窗大小
	cct_setfontsize("新宋体", 36);
	cct_setconsoleborder(formatX, !tag ? formatWITHOUTY : formatWITHY, formatX, !tag ? formatWITHOUTY : formatWITHY);
	cct_setcursor(CURSOR_INVISIBLE);
	// 输出边框
	graphic_head(matrix.column, HEAD, tag, delay);
	
	int cur_x, cur_y;
	cct_getxy(cur_x, cur_y);
	for (int i = 0; i < matrix.row - tag; i++) {  //如果带分割线少画一行
		Sleep(DELAY_TIME);
		cct_showstr(0, cur_y + (tag + 1) * i, "║", COLOR_HWHITE, COLOR_BLACK);  //左边的竖线
		if (tag) {  //中间的竖线
			for (int j = 0; j < matrix.column - 1; j++) {
				cct_showstr(4 + 4 * j, cur_y + (tag + 1) * i, "║", COLOR_HWHITE, COLOR_BLACK);
			}
		}
		cct_showstr((matrix.column + 1 - tag) * (tag + 1) * 2, cur_y + (tag + 1) * i, "║", COLOR_HWHITE, COLOR_BLACK); //右边的竖线
		cout << endl;
		if (tag)  //中间的整行分割线
			graphic_head(matrix.column, DELIMITER, WITH_DELIMITERS, delay);
	}
	if (tag) { 	//把最后一行补上
		for (int i = 0; i < matrix.column + 1; i++) {
			cct_showstr(4 * i, cur_y + 2 * (matrix.row - 1), "║", COLOR_HWHITE, COLOR_BLACK);
		}
		cout << endl;
	}

	
	graphic_head(matrix.column, TAIL, tag, delay);

	//输出球
	for (int i = 0; i < matrix.row; i++) {
		for (int j = 0; j < matrix.column; j++) {  //测试得出 一个横线占两个格子
			
			Sleep(DELAY_TIME / 2);
			cct_showstr(2 + (2 + tag * 2) * j, cur_y + (tag + 1) * i, matrix.arr[i][j].is_triple ? "●" : "〇", matrix.arr[i][j].data + 5, COLOR_BLACK);
		}
	}
	
	cct_gotoxy(0, formatCout1Y);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	cct_setcolor();
}

void graphic_head(const int column, int head, int tag, int delay)  //head = 0 表头 1表尾 2中间 tag = 0不画分割线 1画分割线
{
	//控制延迟时间
	const int DELAY_TIME = delay ? 50 : 0;

	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	if (head == HEAD)
		cout << (!tag ? "╔" : "╔═");
	else if (head == TAIL)
		cout << (!tag ? "╚" : "╚═");
	else
		cout << "╠═";
	for (int i = 0; i < column - tag; i++) {
		if (head == HEAD)
			cout << (!tag ? "═" : "╦═");
		else if (head == TAIL)
			cout << (!tag ? "═" : "╩═");
		else
			cout << "╬═";
		Sleep(DELAY_TIME / 2);
	}
	if (head == HEAD)
		cout << "╗";
	else if (head == TAIL)
		cout << "╝";
	else
		cout << "╣";
	cout << endl;
}

void graphic_exchangeable(const Matrix& matrix, int tag)
{
	cct_setcursor(CURSOR_INVISIBLE);

	for (int i = 0; i < matrix.row; i++) {
		for (int j = 0; j < matrix.column; j++) {
			if (matrix.arr[i][j].is_triple) {
				cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * i,"◎", matrix.arr[i][j].data + 5, (matrix.arr[i][j].is_selected ? COLOR_HWHITE : COLOR_BLACK));
			}
			else
				cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * i, "〇", matrix.arr[i][j].data + 5, COLOR_BLACK);
		}
	}
	
	cct_gotoxy(0, formatCout1Y);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	cct_setcolor();
}

void graphic_eliminate(const Matrix& matrix, int tag)
{
	cct_setcursor(CURSOR_INVISIBLE);

	for (int i = 0; i < matrix.row; i++) {
		for (int j = 0; j < matrix.column; j++) {
			if (matrix.arr[i][j].is_triple) {
				for (int u = 0; u < 3; u++) {  //闪烁动画
					cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * i, "¤", matrix.arr[i][j].data + 5, COLOR_BLACK);
					Sleep(DELAYtiming);
					cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * i, "●", matrix.arr[i][j].data + 5, COLOR_BLACK);
					Sleep(DELAYtiming);
				}				
				cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * i, "¤", COLOR_HWHITE, COLOR_HWHITE);  //消除
			}
		}
	}

	graphic_drop_ball(matrix, tag);

	cct_gotoxy(0, formatCout1Y);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	cct_setcolor();
}

void graphic_drop_ball(const Matrix& matrix, int tag)
{
	for (int j = 0; j < matrix.column; j++) {
		int count = 0; //记录下落格子数
		for (int i = matrix.row - 1; i > -1; i--) {  //从下往上
			if (matrix.arr[i][j].is_triple) {  //空白格子
				count++;
			}
			else { //需要下落的格子
				for (int u = 0; u < count; u++) {
					cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * (i + u), "〇", COLOR_HWHITE, COLOR_HWHITE);  //擦除原来的
					Sleep(DELAYtiming / 3);
					cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * (i + u) + 1, "〇", COLOR_HWHITE, COLOR_BLACK);  //画新的
					Sleep(DELAYtiming / 3);
					cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * (i + u) + 1, "═", COLOR_HWHITE, COLOR_BLACK);  //画新的
					cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * (i + u + 1), "〇", matrix.arr[i][j].data + 5, COLOR_BLACK); //画新的
					Sleep(DELAYtiming / 3);
				}
			}
		}

	}
}

void graphic_refill_matrix(const Matrix& matrix, int tag)
{
	cct_setcursor(CURSOR_INVISIBLE);

	for (int i = 0; i < matrix.row; i++) {
		for (int j = 0; j < matrix.column; j++) {
			if (matrix.arr[i][j].is_triple) {
				cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * i, "〇", matrix.arr[i][j].data + 5, COLOR_BLACK);
				Sleep(DELAYtiming);
			}
		}
	}

	cct_gotoxy(0, formatCout1Y);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	cct_setcolor();
}

void graphic_triple(Matrix& matrix, int tag)
{
	cct_setcursor(CURSOR_INVISIBLE);

	for (int i = 0; i < matrix.row; i++) {
		for (int j = 0; j < matrix.column; j++) {
			if (matrix.arr[i][j].is_triple) {
				cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * i, "●", matrix.arr[i][j].data + 5, COLOR_BLACK);
			}
		}
	}

	cct_gotoxy(0, formatCout1Y);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	cct_setcolor();
}

void graphic_exchange(Matrix& matrix, const node* node1, const node* node2, int tag)
{
	cct_setcursor(CURSOR_INVISIBLE);

	int i1 = (node1 - matrix.arr[0]) / MAXCOLUMN; //行
	int j1 = (node1 - matrix.arr[0]) % MAXCOLUMN; //列
	int i2 = (node2 - matrix.arr[0]) / MAXCOLUMN; //行
	int j2 = (node2 - matrix.arr[0]) % MAXCOLUMN; //列

	cct_showstr(2 + (2 + tag * 2) * j1, 1 + (tag + 1) * i1, "◎", matrix.arr[i1][j1].data + 5, COLOR_BLACK);
	cct_showstr(2 + (2 + tag * 2) * j2, 1 + (tag + 1) * i2, "◎", matrix.arr[i2][j2].data + 5, COLOR_BLACK);

	cct_gotoxy(0, formatCout1Y);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	cct_setcolor();
}



bool test_mouse_position(const int row, const int column, int x, int y, int tag)
{
	//for (int i = 0; i < row; i++)
	//	for (int j = 0; j < column; j++)
	//		if (y == 2 * i + 1 && x == 2 * j + 1)
	//			return true;


	if (y % 2 && 1 <= y && y <= 2 * row - 1)
		if (x % 4 == 2 && 2 <= x && x <= 4 * column - 2
			|| x % 4 == 3 && 3 <= x && x <= 4 * column - 1)  //这里只考虑了tag = 1的情况
			return true;

	return false;
}