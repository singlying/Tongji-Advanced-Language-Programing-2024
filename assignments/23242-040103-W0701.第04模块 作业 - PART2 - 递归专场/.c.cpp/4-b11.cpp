
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
				 2、除print_tower之外的其他函数中不允许定义静态局部变量
   ----------------------------------------------------------------------------------- */

void circle_2(char ch, const char end, int order) //order : 1 正序 0逆序
{
	if (ch == end && order) {
		cout << ch;
		return;
	}
	else if (ch == 'A' && 'A' != end) {
		cout << 'A';
		circle_2(ch + 1, end, 1);
		return;
	}
	else if (end == 'A') {
		cout << 'A';
		return;
	}
	else if (!order) {
		cout << ch;
		circle_2(ch - 1, end, 0);
		return;
	}
	else {
		cout << ch;
		circle_2(ch + 1, end, 1);
	}
}

void circle_1(int num, const int sum, int order) //order : 1 正序 0逆序
{
	if (!num) {
		return;
	}
	else if (order){ //正序
		circle_1(num - 1, sum, 1);

		cout << setw(sum - num) << setfill(' ') << "";
		circle_2(char('A' + num - 1), char('A' + num - 1), 0);
		cout << endl;
	}
	else { //逆序
		cout << setw(sum - num) << setfill(' ') << "";
		circle_2(char('A' + num - 1), char('A' + num - 1), 0);
		cout << endl;

		circle_1(num - 1, sum, 0);
	}
}


   /***************************************************************************
	 函数名称：
	 功    能：打印字母塔
	 输入参数：
	 返 回 值：
	 说    明：形参按需设置
			   提示：有一个参数order，指定正序/倒序
   ***************************************************************************/
   /* 允许按需定义最多一个静态局部变量（也可以不定义） */
	   /* 按需实现，函数中不允许任何形式的循环，函数允许调用其它函数 */
void print_tower(char ch, int order, int adjustment) //order: 1 正序 0 逆序 adjustment 是否调整缩进: 1 增加缩进 0 不调整
{
	if (order && !adjustment) { //正序 不调整缩进
		circle_1(ch - 'A' + 1, ch - 'A' + 1, 1);
	}
	else if (!order && !adjustment) { //逆序 不调整缩进
		circle_1(ch - 'A' + 1, ch - 'A' + 1, 0);
	}
	else if (order && adjustment) { //正序 调整缩进
		circle_1(ch - 'A' + 1, ch - 'A' + 2, 1);
	}
	else { //逆序 调整缩进
		circle_1(ch - 'A' + 1, ch - 'A' + 2, 0);
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(中间为A) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch, 1, 0); //正序打印 A~结束字符 
	cout << endl;

	/* 倒三角字母塔(中间为A) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch, 0, 0); //逆序打印 A~结束字符 
	cout << endl;

	/* 合起来就是漂亮的菱形（中间为A） */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "" << endl;/* 按字母塔最大宽度输出= */
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "" << endl;/* 按字母塔最大宽度输出= */
	print_tower(end_ch, 1, 0);  //打印 A~结束字符的正三角 
	print_tower(end_ch - 1, 0, 1);   //打印 A~结束字符-1的倒三角 
	cout << endl;

	return 0;
}
