
#include <iostream>
#include<iomanip>
using namespace std;

int zeller(int y, int m, int d)
{
	if (m <= 2) {
		m += 12;
		y--;
	}
	int c = y / 100;
	y %= 100;

	int w = y + y / 4 + c / 4 - 2 * c + (13 * (m + 1) / 5) + d - 1;

	return (w % 7 + 7) % 7;
}

void calender(int year, int month)
{
	//判断闰年
	int leap_year = -1;
	if (year % 4 == 0) {
		leap_year = 1;
		if (year % 100 == 0) {
			if (year % 400 == 0)
				leap_year = 1;
			else
				leap_year = 0;
		}
	}
	else
		leap_year = 0;

	int start_day = zeller(year, month, 1); //1号的星期

	cout << endl << year << "年" << month << "月" << endl;
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;

	for (int i = 0; i < start_day; i++) { //开始的空格
		cout << "        ";
	}

	int meta_day = 0; //用来调整月份的天数
	int day_num = 1; //当前日期

	//调整meta_day
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) { //1 3 5 7 8 10 12月
		meta_day = 3;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) { //4 6 9 11月
		meta_day = 2;
	}
	else if (month == 2 && leap_year) { //闰2月
		meta_day = 1;
	}

	while (day_num <= 28 + meta_day) {
		cout << setw(4) << day_num << "    ";
		if ((start_day + day_num) % 7 == 0) {
			cout << endl;
		}
		day_num++;
	}
	if ((start_day - 1 + day_num) % 7) {
		cout << endl;
	}

	cout << "======================================================" << endl;
}

int main()
{
	int year, month;

	//输入
	while (1) {
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> year;
		cin >> month;

		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入错误，请重新输入" << endl;
		}
		else if (year < 1900 || year > 2100) {
			cout << "年份不正确，请重新输入" << endl;
		}
		else if (month > 12 || month < 1) {
			cout << "月份不正确，请重新输入" << endl;
		}
		else
			break;

	}

	calender(year, month);

	return 0;
}