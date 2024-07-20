
#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
	int year, month, start_day; //年，月，星期

	//输入
	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> year;
		cin >> month;

		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (year <= 2030 && year >= 2000 && month >= 1 && month <= 12) {
			break;
		}

		cout << "输入非法，请重新输入" << endl;
	}

	while (1) {
		cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) : "; //这个地方没有换行符
		cin >> start_day;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (start_day >= 0 && start_day <= 6) {
			break;
		}

		cout << "输入非法，请重新输入" << endl;
	}

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

	//打印
	cout << endl << year << "年" << month << "月的月历为:" << endl; //这个地方最开始有一个换行符
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;

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

	cout << endl;

	return 0;
}