
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int is_leap_year(int year) //判断闰年
{
	int leap_year = 0;
	//判断闰年
	if (year % 4 == 0) {
		leap_year = 1;
		if (year % 100 == 0) {
			if (year % 400 == 0)
				leap_year = 1;
			else
				leap_year = 0;
		}
	}

	return leap_year;
}

int which_day(int year, int month, int day) //返回天数
{
	const int month_day[] = { 31,28 + is_leap_year(year),31,30,31,30,31,31,30,31,30,31 };

	int count = 0;
	for (int i = 0; i < month - 1; i++) {
		count += month_day[i];
	}

	return count += day;
}

int main()
{
	int year, month, day;
	printf("请输入年，月，日\n");
	scanf("%d %d %d", &year, &month, &day);

	//判断月份合法  
	if (month > 12 || month < 1) {
		printf("输入错误-月份不正确\n");
		return 0;
	}

	//天数
	const int month_day[] = { 31,28 + is_leap_year(year),31,30,31,30,31,31,30,31,30,31 };

	//判断日期合法
	if (day > month_day[month - 1] || day < 0) {
		printf("输入错误-日与月的关系非法\n");
		return 0;
	}

	printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, which_day(year, month, day));
	return 0;
}