
#include <iostream>
#include <iomanip>
using namespace std;

//将年月日转换为星期
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

//判断闰年
bool is_leap_year(int year)
{
	bool leap_year = 1;
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0)
				leap_year = 1;
			else
				leap_year = 0;
		}
	}
	else
		leap_year = 0;

	return leap_year;
}

//打印表头
void print_table(int i) //i为第几轮输出 ，一共4轮输出 0 ~ 3
{
	i = i * 3 + 1;
	cout << endl << "           " << right << setw(2) << i << "月" << "                            " << setw(2)
		<< i + 1 << "月" << "                            " << setw(2) << i + 2 << "月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
}

//打印第i轮的3个月份
void print_month(int year, int i)
{
	const int month_day[13] = {0,31,28 + is_leap_year(year),31,30,31,30,31,31,30,31,30,31 }; //记录月份的天数
	int day_pointer[13]; //每月天数的指针  范围1 ~ month_day[i]  表示要下一次要输出的一天
	int start_day[13] = { 0 };

	for (int i = 0; i < 13; i++) //初始化为1
		day_pointer[i] = 1;

	for (int i = 1; i < 13; i++) {
		start_day[i] = zeller(year, i, 1);
	}

	print_table(i);

	int start_month = i * 3 + 1; //初始月份
	int now_month = start_month; //当前月份


	while (day_pointer[start_month] <= month_day[start_month] || day_pointer[start_month + 1] <=
		month_day[start_month + 1] || day_pointer[start_month + 2] <= month_day[start_month + 2]) {
		while (now_month < i * 3 + 4) {
			if (day_pointer[now_month] == 1) //如果刚开始输出这个月的day
				for (int i = 0; i < start_day[now_month]; i++) { //输出开始的空格
					cout << "    ";
				}

			if (day_pointer[now_month] > month_day[now_month]) { //这个月已经输出完
				cout << setw(4 * 8) << " ";
				now_month++;
				continue;
			}

			//输出day
			while (day_pointer[now_month] <= month_day[now_month]) {
				//cout << setiosflags(ios::left) << setw(4) << day_pointer[now_month];
				cout << left << setw(4) << day_pointer[now_month];
				if ((start_day[now_month] + day_pointer[now_month]) % 7 == 0) {
					day_pointer[now_month]++;
					break;
				}
				day_pointer[now_month]++;
			}

			if (now_month % 3) //月份中间的空格  4 +   
				cout << setw(4 + 4 * ((7 - (start_day[now_month] + day_pointer[now_month] - 1) % 7) % 7)) << " ";
			else if (now_month % 3 == 0 && (day_pointer[start_month] <= month_day[start_month] || day_pointer[start_month + 1] <=
				month_day[start_month + 1] || day_pointer[start_month + 2] <= month_day[start_month + 2]))
				cout << endl;

			now_month++;
		}

		now_month = start_month;
	}
}

int main()
{
	int year;
	cout << "请输入年份[1900-2100]" << endl;
	cin >> year;
	cout << year << "年的日历:" << endl;

	for (int i = 0; i < 4; i++) {
		print_month(year, i);
		cout << endl;
	}

	cout << endl << endl;

	return 0;
}