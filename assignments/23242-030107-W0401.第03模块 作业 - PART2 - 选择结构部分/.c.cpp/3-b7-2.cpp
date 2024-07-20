
#include<iostream>
#include <cmath>
using namespace std;

int main() 
{
	cout << "请输入找零值：" << endl;

	double num; //钱数
	int count = 0; //张数
	cin >> num;

	//提取整数部分和小数部分
	int integer = (int)num;  //整数值
	double decimal = num - integer;
	int digit_1 = (int)(round((num - floor(num)) * 100)) / 10 % 10;
	int digit_2 = (int)(round((num - floor(num)) * 100)) % 10;
	int int_decimal = digit_1 * 10 + digit_2;  //小数值

	int yuan_50 = 0, yuan_20 = 0, yuan_10 = 0, yuan_5 = 0, yuan_1 = 0,
		jiao_5 = 0, jiao_1 = 0, fen_5 = 0, fen_2 = 0, fen_1 = 0;

	//整数部分
	if (yuan_50 = integer / 50) {
		integer %= 50;
		count += yuan_50;
	}

	if (yuan_20 = integer / 20) {
		integer %= 20;
		count += yuan_20;
	}

	if (yuan_10 = integer / 10) {
		integer %= 10;
		count += yuan_10;
	}

	if (yuan_5 = integer / 5) {
		integer %= 5;
		count += yuan_5;
	}

	if (yuan_1 = integer) {
		count += yuan_1;
	}

	//小数部分
	if (jiao_5 = int_decimal / 50) {
		int_decimal %= 50;
		count += jiao_5;
	}

	if (jiao_1 = int_decimal / 10) {
		int_decimal %= 10;
		count += jiao_1;
	}

	if (fen_5 = int_decimal / 5) {
		int_decimal %= 5;
		count += fen_5;
	}

	if (fen_2 = int_decimal / 2) {
		int_decimal %= 2;
		count += fen_2;
	}

	if (fen_1 = int_decimal) {
		count += fen_1;
	}

	cout << "共" << count << "张找零，具体如下：" << endl;
	if (yuan_50) {
		cout << "50元 : " << yuan_50 << "张" << endl;
	}

	if (yuan_20) {
		cout << "20元 : " << yuan_20 << "张" << endl;
	}

	if (yuan_10) {
		cout << "10元 : " << yuan_10 << "张" << endl;
	}

	if (yuan_5) {
		cout << "5元  : " << yuan_5 << "张" << endl;
	}

	if (yuan_1) {
		cout << "1元  : " << yuan_1 << "张" << endl;
	}

	if (jiao_5) {
		cout << "5角  : " << jiao_5 << "张" << endl;
	}

	if (jiao_1) {
		cout << "1角  : " << jiao_1 << "张" << endl;
	}

	if (fen_5) {
		cout << "5分  : " << fen_5 << "张" << endl;
	}

	if (fen_2) {
		cout << "2分  : " << fen_2 << "张" << endl;
	}

	if (fen_1) {
		cout << "1分  : " << fen_1 << "张" << endl;
	}

	return 0;
}