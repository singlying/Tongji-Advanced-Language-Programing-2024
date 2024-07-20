
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <ctime>
#include "magic_ball.h"
#include "cmd_console_tools.h"
using namespace std;

//������ ��������
//���� ��ʼ����������
//���� ��ʾ�ɽ�������  �а�ɫ ��ɫ
//���� �����е�Ч��
// ��-�� Hello, I am BAYMAX!


//������ HWHITE  ǰ��BLACK

void graph_matrix(const Matrix& matrix, int tag, int delay) //tag = 0�����ָ��� 1���ָ��� delay = 0���ӳ� 1�ӳ�
{
	//�����ӳ�ʱ��
	const int DELAY_TIME = delay ? 50 : 0;
	//�����Ӵ���С
	cct_setfontsize("������", 36);
	cct_setconsoleborder(formatX, !tag ? formatWITHOUTY : formatWITHY, formatX, !tag ? formatWITHOUTY : formatWITHY);
	cct_setcursor(CURSOR_INVISIBLE);
	// ����߿�
	graphic_head(matrix.column, HEAD, tag, delay);
	
	int cur_x, cur_y;
	cct_getxy(cur_x, cur_y);
	for (int i = 0; i < matrix.row - tag; i++) {  //������ָ����ٻ�һ��
		Sleep(DELAY_TIME);
		cct_showstr(0, cur_y + (tag + 1) * i, "�U", COLOR_HWHITE, COLOR_BLACK);  //��ߵ�����
		if (tag) {  //�м������
			for (int j = 0; j < matrix.column - 1; j++) {
				cct_showstr(4 + 4 * j, cur_y + (tag + 1) * i, "�U", COLOR_HWHITE, COLOR_BLACK);
			}
		}
		cct_showstr((matrix.column + 1 - tag) * (tag + 1) * 2, cur_y + (tag + 1) * i, "�U", COLOR_HWHITE, COLOR_BLACK); //�ұߵ�����
		cout << endl;
		if (tag)  //�м�����зָ���
			graphic_head(matrix.column, DELIMITER, WITH_DELIMITERS, delay);
	}
	if (tag) { 	//�����һ�в���
		for (int i = 0; i < matrix.column + 1; i++) {
			cct_showstr(4 * i, cur_y + 2 * (matrix.row - 1), "�U", COLOR_HWHITE, COLOR_BLACK);
		}
		cout << endl;
	}

	
	graphic_head(matrix.column, TAIL, tag, delay);

	//�����
	for (int i = 0; i < matrix.row; i++) {
		for (int j = 0; j < matrix.column; j++) {  //���Եó� һ������ռ��������
			
			Sleep(DELAY_TIME / 2);
			cct_showstr(2 + (2 + tag * 2) * j, cur_y + (tag + 1) * i, matrix.arr[i][j].is_triple ? "��" : "��", matrix.arr[i][j].data + 5, COLOR_BLACK);
		}
	}
	
	cct_gotoxy(0, formatCout1Y);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	cct_setcolor();
}

void graphic_head(const int column, int head, int tag, int delay)  //head = 0 ��ͷ 1��β 2�м� tag = 0�����ָ��� 1���ָ���
{
	//�����ӳ�ʱ��
	const int DELAY_TIME = delay ? 50 : 0;

	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	if (head == HEAD)
		cout << (!tag ? "�X" : "�X�T");
	else if (head == TAIL)
		cout << (!tag ? "�^" : "�^�T");
	else
		cout << "�d�T";
	for (int i = 0; i < column - tag; i++) {
		if (head == HEAD)
			cout << (!tag ? "�T" : "�j�T");
		else if (head == TAIL)
			cout << (!tag ? "�T" : "�m�T");
		else
			cout << "�p�T";
		Sleep(DELAY_TIME / 2);
	}
	if (head == HEAD)
		cout << "�[";
	else if (head == TAIL)
		cout << "�a";
	else
		cout << "�g";
	cout << endl;
}

void graphic_exchangeable(const Matrix& matrix, int tag)
{
	cct_setcursor(CURSOR_INVISIBLE);

	for (int i = 0; i < matrix.row; i++) {
		for (int j = 0; j < matrix.column; j++) {
			if (matrix.arr[i][j].is_triple) {
				cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * i,"��", matrix.arr[i][j].data + 5, (matrix.arr[i][j].is_selected ? COLOR_HWHITE : COLOR_BLACK));
			}
			else
				cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * i, "��", matrix.arr[i][j].data + 5, COLOR_BLACK);
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
				for (int u = 0; u < 3; u++) {  //��˸����
					cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * i, "��", matrix.arr[i][j].data + 5, COLOR_BLACK);
					Sleep(DELAYtiming);
					cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * i, "��", matrix.arr[i][j].data + 5, COLOR_BLACK);
					Sleep(DELAYtiming);
				}				
				cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * i, "��", COLOR_HWHITE, COLOR_HWHITE);  //����
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
		int count = 0; //��¼���������
		for (int i = matrix.row - 1; i > -1; i--) {  //��������
			if (matrix.arr[i][j].is_triple) {  //�հ׸���
				count++;
			}
			else { //��Ҫ����ĸ���
				for (int u = 0; u < count; u++) {
					cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * (i + u), "��", COLOR_HWHITE, COLOR_HWHITE);  //����ԭ����
					Sleep(DELAYtiming / 3);
					cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * (i + u) + 1, "��", COLOR_HWHITE, COLOR_BLACK);  //���µ�
					Sleep(DELAYtiming / 3);
					cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * (i + u) + 1, "�T", COLOR_HWHITE, COLOR_BLACK);  //���µ�
					cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * (i + u + 1), "��", matrix.arr[i][j].data + 5, COLOR_BLACK); //���µ�
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
				cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * i, "��", matrix.arr[i][j].data + 5, COLOR_BLACK);
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
				cct_showstr(2 + (2 + tag * 2) * j, 1 + (tag + 1) * i, "��", matrix.arr[i][j].data + 5, COLOR_BLACK);
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

	int i1 = (node1 - matrix.arr[0]) / MAXCOLUMN; //��
	int j1 = (node1 - matrix.arr[0]) % MAXCOLUMN; //��
	int i2 = (node2 - matrix.arr[0]) / MAXCOLUMN; //��
	int j2 = (node2 - matrix.arr[0]) % MAXCOLUMN; //��

	cct_showstr(2 + (2 + tag * 2) * j1, 1 + (tag + 1) * i1, "��", matrix.arr[i1][j1].data + 5, COLOR_BLACK);
	cct_showstr(2 + (2 + tag * 2) * j2, 1 + (tag + 1) * i2, "��", matrix.arr[i2][j2].data + 5, COLOR_BLACK);

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
			|| x % 4 == 3 && 3 <= x && x <= 4 * column - 1)  //����ֻ������tag = 1�����
			return true;

	return false;
}