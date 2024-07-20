
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

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


int main()
{
	int year, month, day;
	int leap_year = 0;
	while (1) {
		printf("请输入年[1900-2100]、月、日：\n");
		int ret = scanf("%d%d%d", &year, &month, &day);
		if (ret != 3) {
			printf("输入错误，请重新输入\n");
			while (getchar() != '\n') {
			};
			continue;
		}
		
		if (year < 1900 || year > 2100) { //判断年份
			printf("年份不正确，请重新输入\n");
			continue;
		}
		else { //判断闰年
			if (year % 4 == 0) {
				leap_year = 1;
				if (year % 100 == 0) {
					leap_year = 0;
					if (year % 400 == 0)
						leap_year = 1;
				}
			}
			else
				leap_year = 0;
		}

		if (month > 12 || month < 1) { //判断月份
			printf("月份不正确，请重新输入\n");
			continue;
		}

		if (month == 1 || month == 3 || month == 5 || month == 7 ||
			month == 8 || month == 10 || month == 12) { //判断日期
			if (day > 31 || day < 1) {
				printf("日不正确，请重新输入\n");
				continue;
			}
		}
		else if (month == 2) {
			if (leap_year && (day > 29 || day < 1)) {
				printf("日不正确，请重新输入\n");
				continue;
			}
			else if (!leap_year && (day > 28 || day < 1)) {
				printf("日不正确，请重新输入\n");
				continue;
			}
		}
		else {
			if (day > 30 || day < 1) {
				printf("日不正确，请重新输入\n");
				continue;
			}
		}

		break;
	}

	int week = zeller(year, month, day);

	switch (week)
	{
		case 0:
			printf("星期日\n");
			break;
		case 1:
			printf("星期一\n");
			break;
		case 2:
			printf("星期二\n");
			break;
		case 3:
			printf("星期三\n");
			break;
		case 4:
			printf("星期四\n");
			break;
		case 5:
			printf("星期五\n");
			break;
		case 6:
			printf("星期六\n");
			break;
	}

	return 0;
}