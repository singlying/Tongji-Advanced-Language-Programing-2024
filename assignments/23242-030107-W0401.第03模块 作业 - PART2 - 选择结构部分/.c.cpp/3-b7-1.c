
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	printf("����������ֵ��\n");
	double num; //Ǯ��
	int count = 0; //����
	int an_attempt_to_remove_this_warning = scanf("%lf", &num);

	//��ȡ�������ֺ�С������
	int integer = (int)num;  //����ֵ
	double decimal = num - integer;
	int digit_1 = (int)(round((num - floor(num)) * 100)) / 10 % 10;
	int digit_2 = (int)(round((num - floor(num)) * 100)) % 10;
	int int_decimal = digit_1 * 10 + digit_2;  //С��ֵ

	int yuan_50 = 0, yuan_20 = 0, yuan_10 = 0, yuan_5 = 0, yuan_1 = 0,
		jiao_5 = 0, jiao_1 = 0, fen_5 = 0, fen_2 = 0, fen_1 = 0;
	
	//��������
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

	//С������
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

	///////
	printf("��%d�����㣬�������£�\n", count);
	if (yuan_50) {
		printf("50Ԫ : %d��\n", yuan_50);
	}

	if (yuan_20) {
		printf("20Ԫ : %d��\n", yuan_20);
	}

	if (yuan_10) {
		printf("10Ԫ : %d��\n", yuan_10);
	}

	if (yuan_5) {
		printf("5Ԫ  : %d��\n", yuan_5);
	}

	if (yuan_1) {
		printf("1Ԫ  : %d��\n", yuan_1);
	}

	if (jiao_5) {
		printf("5��  : %d��\n", jiao_5);
	}

	if (jiao_1) {
		printf("1��  : %d��\n", jiao_1);
	}

	if (fen_5) {
		printf("5��  : %d��\n", fen_5);
	}

	if (fen_2) {
		printf("2��  : %d��\n", fen_2);
	}

	if (fen_1) {
		printf("1��  : %d��\n", fen_1);
	}
	///////

	return 0;
}