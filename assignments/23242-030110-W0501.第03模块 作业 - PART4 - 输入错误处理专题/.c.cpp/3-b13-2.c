
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year, month, start_day; //�꣬�£�����

	//����
	while (1) {
		printf("���������(2000-2030)���·�(1-12) : ");
		int ret = scanf("%d%d", &year, &month);
		if (ret != 2) {
			while (getchar() != '\n') {
			};
		}
		else if (year <= 2030 && year >= 2000 && month >= 1 && month <= 12) {
			break;
		}

		printf("����Ƿ�������������\n");
	}

	while (1) {
		printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ", year, month);
		int ret = scanf("%d", &start_day);
		if (ret != 1) {
			while (getchar() != '\n') {
			};
		}
		else if (start_day >= 0 && start_day <= 6) {
			break;
		}

		printf("����Ƿ�������������\n");
	}

	//�ж�����
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

	//��ӡ
	printf("\n%d��%d�µ�����Ϊ:\n", year, month); //����ط��ʼ��һ�����з�
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");

	for (int i = 0; i < start_day; i++) { //��ʼ�Ŀո�
		printf("        ");
	}

	int meta_day = 0; //���������·ݵ�����

	int day_num = 1; //��ǰ����

	//����meta_day
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) { //1 3 5 7 8 10 12��
		meta_day = 3;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) { //4 6 9 11��
		meta_day = 2;
	}
	else if (month == 2 && leap_year) { //��2��
		meta_day = 1;
	}

	while (day_num <= (28 + meta_day)) {
		printf("%4d    ", day_num);
		if ((start_day + day_num) % 7 == 0) {
			printf("\n");
		}
		day_num++;
	}

	printf("\n");

	return 0;
}