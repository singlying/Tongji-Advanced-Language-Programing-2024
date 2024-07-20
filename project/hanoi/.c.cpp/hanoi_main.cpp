
#include <iostream>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;
/* ----------------------------------------------------------------------------------
     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）
     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等
   ----------------------------------------------------------------------------------- */

int main()
{
	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);

	//cct_setcolor(); //恢复缺省颜色

	int n;
	char src, tmp, dst; //src起始 tmp中间 dst目标
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
			case 5:  //画柱子
				print_Column();
				break;
			case 6:  //画盘子
				input(n, src, tmp, dst, delay);
				Initia_arr(src, n);
				print_Column();
				print_Plate();
				break;
			case 7:  //第一次移动
				input(n, src, tmp, dst, delay);
				Initia_arr(src, n);
				print_Column();
				print_Plate();
				MovePlate(src, n % 2 ? dst : tmp, 4);  //规律显示，第一次移动方向和n % 2有关
				break;
			case 8:  //自动移动
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