
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
			char ch    ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
int menu(const HANDLE hout)
{
	int choose;
	while (1) {
		printf("1.用I、J、K、L键控制上下左右(大小写均可，边界停止)\n");
		printf("2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)\n");
		printf("3.用箭头键控制上下左右，边界停止\n");
		printf("4.用箭头键控制上下左右，边界回绕\n");
		printf("5.用I、J、K、L键控制上下左右(按左箭头键不向下移动，大小写均可，边界停止\n");
		printf("6.用I、J、K、L键控制上下左右(按左箭头键不向下移动，大小写均可，边界回绕\n");
		printf("0.退出\n[请选择0-6] ");

		choose = _getch();
		if (choose <= '6' && choose >= '0')
			break;
		else
			cls(hout);
	}

	return choose;
}

void move_by_ijkl(const HANDLE hout, int tag, int bonus_question) //tag: 0边界停止 1边界回绕 bonus_question: 0 不处理左箭头 1处理左箭头
{
	cls(hout);
	init_border(hout);

	gotoxy(hout, 35, 9);
	int x = 35, y = 9; //当前坐标
	int arrow; //输入方向

	while (1) {
		arrow = _getch();

		//处理向左箭头
		if (bonus_question && arrow == 224) {
			arrow = _getch();
			continue;
		}

		//处理光标移动
		if (arrow == 'i' || arrow == 'I') {
			if (y == 1) {
				if (!tag)
					y++;
				else
					y = 18;
			}
			gotoxy(hout, x, --y);
		}
		else if (arrow == 'j' || arrow == 'J') {
			if (x == 1) {
				if (!tag)
					x++;
				else
					x = 70;
			}
			gotoxy(hout, --x, y);
		}
		else if (arrow == 'k' || arrow == 'K') {
			if (y == 17) {
				if (!tag)
					y--;
				else
					y = 0;
			}
			gotoxy(hout, x, ++y);
		}
		else if (arrow == 'l' || arrow == 'L') {
			if (x == 69) {
				if (!tag)
					x--;
				else
					x = 0;
			}
			gotoxy(hout, ++x, y);
		}

		//处理空格
		if (arrow == ' ') {
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
		}

		//处理q返回
		if (arrow == 'q' || arrow == 'Q') {
			gotoxy(hout, 0, 23);
			printf("游戏结束，按回车键返回菜单.");

			while (1)
			{
				arrow = _getch();
				if (arrow == '\r')
				{
					cls(hout);
					gotoxy(hout, 0, 0);
					return;
				}
			}
		}
	}
}

void move_by_arrow(const HANDLE hout,  int tag) //tag: 0边界停止 1边界回绕
{
	cls(hout);
	init_border(hout);

	gotoxy(hout, 35, 9);
	int x = 35, y = 9; //当前坐标
	int arrow; //输入方向


	while (1) {
		arrow = _getch();
		if (arrow == 224) { //输入方向键_getch()会读取两次
			arrow = _getch();

			//处理光标移动
			if (arrow == 72) { //i
				if (y == 1) {
					if (!tag)
						y++;
					else
						y = 18;
				}
				gotoxy(hout, x, --y);
			}
			else if (arrow == 75) { //j
				if (x == 1) {
					if (!tag)
						x++;
					else
						x = 70;
				}
				gotoxy(hout, --x, y);
			}
			else if (arrow == 80) { //k
				if (y == 17) {
					if (!tag)
						y--;
					else
						y = 0;
				}
				gotoxy(hout, x, ++y);
			}
			else if (arrow == 77) { //l
				if (x == 69) {
					if (!tag)
						x--;
					else
						x = 0;
				}
				gotoxy(hout, ++x, y);
			}
		}

		//处理空格
		if (arrow == ' ') {
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
		}

		//处理q返回
		if (arrow == 'q' || arrow == 'Q') {
			gotoxy(hout, 0, 23);
			printf("游戏结束，按回车键返回菜单.");

			while (1)
			{
				arrow = _getch();
				if (arrow == '\r')
				{
					cls(hout);
					gotoxy(hout, 0, 0);
					return;
				}
			}
		}
	}
}

int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	//生成伪随机数的种子
	srand((unsigned int)(time(0)));

	int choose;
	while (1) {
		choose = menu(hout);

		switch (choose)
		{
			case '1':
				move_by_ijkl(hout, 0, 0);
				break;
			case '2':
				move_by_ijkl(hout, 1, 0);
				break;
			case '3':
				move_by_arrow(hout, 0);
				break;
			case '4':
				move_by_arrow(hout, 1);
				break;
			case '5':
				move_by_ijkl(hout, 0, 1);
				break;
			case '6':
				move_by_ijkl(hout, 1, 1);
				break;
			case '0':
				return 0;
		}
	}

	return 0;
}

//关于字母数字不一定为20个：
//在两个或多个字母的位置重叠的时候不到20个