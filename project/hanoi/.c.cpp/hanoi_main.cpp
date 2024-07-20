
#include <iostream>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;
/* ----------------------------------------------------------------------------------
     ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�
     ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��
   ----------------------------------------------------------------------------------- */

int main()
{
	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(120, 40, 120, 9000);

	//cct_setcolor(); //�ָ�ȱʡ��ɫ

	int n;
	char src, tmp, dst; //src��ʼ tmp�м� dstĿ��
	int delay;
	int select;

	while (1) {
		select = Menu();
		delay = -1;
		switch (select) {
			case 1:
			case 2:
				input(n, src, tmp, dst, delay);
				hanoi(n, src, tmp, dst, select, delay);
				break;
			case 3:
			case 4:
				input(n, src, tmp, dst, delay = select - 4);
				Initia_arr(src, n);
				hanoi(n, src, tmp, dst, select, delay);
				break;
			case 5:  //������
				print_Column();
				break;
			case 6:  //������
				input(n, src, tmp, dst, delay);
				Initia_arr(src, n);
				print_Column();
				print_Plate();
				break;
			case 7:  //��һ���ƶ�
				input(n, src, tmp, dst, delay);
				Initia_arr(src, n);
				print_Column();
				print_Plate();
				MovePlate(src, n % 2 ? dst : tmp, 4);  //������ʾ����һ���ƶ������n % 2�й�
				break;
			case 8:  //�Զ��ƶ�
				input(n, src, tmp, dst, delay = 0);
				Initia_arr(src, n);
				print_Column();
				print_Plate();
				cct_gotoxy(h_x, h_y_2);
				print_stack();
				Graphic(1);
				hanoi(n, src, tmp, dst, select, delay);
				break;
			case 9:
				input(n, src, tmp, dst, delay);
				Initia_arr(src, n);
				print_Column();
				print_Plate();
				cct_gotoxy(h_x, h_y_2);
				print_stack();
				Graphic(1);
				MyGame(n, src, dst);
				break;
			case 0:
				return 0;
			default:
				break;
		}

		to_be_continued();
	}
	return 0;
}