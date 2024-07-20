
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "请输入[0-100 亿)之间的数字:" << endl;

	double num;
	cin >> num;

	//提取整数部分和小数部分
	long long integer = (long long)num;
	double decimal = num - integer;

	//打印整数部分
	cout << "十亿位 : " << integer / int(1e9) << endl;
	cout << "亿位   : " << integer % int(1e9) / int(1e8) << endl;
	cout << "千万位 : " << integer % int(1e8) / int(1e7) << endl;
	cout << "百万位 : " << integer % int(1e7) / int(1e6) << endl;
	cout << "十万位 : " << integer % int(1e6) / int(1e5) << endl;
	cout << "万位   : " << integer % int(1e5) / int(1e4) << endl;
	cout << "千位   : " << integer % int(1e4) / int(1e3) << endl;
	cout << "百位   : " << integer % int(1e3) / int(1e2) << endl;
	cout << "十位   : " << integer % int(1e2) / int(1e1) << endl;
	cout << "圆     : " << integer % 10 << endl;

	//打印小数部分
	//通过进位取余运算消除误差，仅适用于两位小数的情况
	int digit_1 = int(decimal * 10);       //小数第一位
	int digit_2 = int(decimal * 100) % 10; //小数第二位
	int digit_3 = int(decimal * 1000) % 10;//小数第三位 只可能是0或者9
	cout << "角     : " << (((digit_2 + digit_3) / 10 + digit_2) / 10 + digit_1) % 10 << endl;
	cout << "分     : " << (((digit_2 + digit_3) / 10 + digit_2) % 10) << endl;


	return 0;
}