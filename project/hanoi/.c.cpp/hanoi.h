
#pragma once
/* ------------------------------------------------------------------------------------------------------
     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */

//黑白图形化用到的定位
#define g_x 25 //图形化的初始x
#define g_y 15 //图形化的初始y
#define h_x g_x //显示步数初始x
#define h_y g_y + 5 //显示步数初始y

#define g_y_2 28 //pattern_7的图形化初始x
#define h_y_2 g_y_2 + 5  //pattern_7显示步数初始y

//游戏用到的定位
#define game_notion_y h_y_2 + 2  //游戏提示语位置的y
#define game_notion_x 60   //游戏提示语位置的x

//彩色柱子用到的定位
#define column_x 24  //柱子的宽
#define column_h 12  //柱子的高
#define column_space 10 //柱子间的宽度
#define A_column_middle_x column_space + column_x / 2 //A柱x坐标
#define B_column_middle_x column_space * 2 + column_x + column_x / 2 //B柱x坐标
#define C_column_middle_x column_space * 3 + 2 * column_x + column_x / 2 //C柱x坐标
#define column_bottom_y column_h + column_space / 2  //柱子底部的y坐标

//assisting functions
//整形输入辅助函数
int input_tools(const int min, const int max, const char prompt[]);

//入栈
void push(char arr, int x);

//出栈
int pop(char arr);

//打印栈
void print_stack();

//按任意键继续
void to_be_continued();

//main functions
// 通过pattern来调整不同的模式选择  pattern << 1 2 3 4 8 9
//主菜单
int Menu();

//主递归
void hanoi(int n, char src, char tmp, char dst, int pattern, int delay); 

//主显示函数
void MainDisplay(int n, char src, char dst, char pattern, int delay);

//图形化
void Graphic(int pattern);  //pattern {0: 4的图形化  1:8、9的图形化}

//分段延迟函数
void MySleep(int delay); 

//主输入函数
void input(int& n, char& src, char& tmp, char& dst, int& delay);

//初始化数组
void Initia_arr(int arr, int n);

//清空数组
void empty_arr();

//画柱子
void print_Column();

//画盘子
void print_Plate();

//移动盘子
void MovePlate(char src, char dst, int delay);

//Mygame
void MyGame(int n, char src, char dst);

//is_GameEnd
bool is_GameEnd(int n, char src, char dst);

//GameErrorTips
void GameErrorTips(const char arr[]);

//GameInput_tools
int GameInput_tools(char a[]);