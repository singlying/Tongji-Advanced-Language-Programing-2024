
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int is_leap_year(int year) //�ж�����
{
	int leap_year = 0;
	//�ж�����
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

int which_day(int year, int month, int day) //��������
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
	printf("�������꣬�£���\n");
	scanf("%d %d %d", &year, &month, &day);

	//�ж��·ݺϷ�  
	if (month > 12 || month < 1) {
		printf("�������-�·ݲ���ȷ\n");
		return 0;
	}

	//����
	const int month_day[] = { 31,28 + is_leap_year(year),31,30,31,30,31,31,30,31,30,31 };

	//�ж����ںϷ�
	if (day > month_day[month - 1] || day < 0) {
		printf("�������-�����µĹ�ϵ�Ƿ�\n");
		return 0;
	}

	printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, which_day(year, month, day));
	return 0;
}