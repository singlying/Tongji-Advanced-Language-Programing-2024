
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("������[0-100 ��)֮�������:\n");

	double num;	
	scanf("%lf", &num);
	     
	//��ȡ�������ֺ�С������
	long long integer = (long long)num;
	double decimal = num - integer;
	
	//��ӡ��������
	printf("ʮ��λ : %lld\n", integer / (int)1e9);
	printf("��λ   : %lld\n", integer % (int)1e9 / (int)1e8);
	printf("ǧ��λ : %lld\n", integer % (int)1e8 / (int)1e7);
	printf("����λ : %lld\n", integer % (int)1e7 / (int)1e6);
	printf("ʮ��λ : %lld\n", integer % (int)1e6 / (int)1e5);
	printf("��λ   : %lld\n", integer % (int)1e5 / (int)1e4);
	printf("ǧλ   : %lld\n", integer % (int)1e4 / (int)1e3);
	printf("��λ   : %lld\n", integer % (int)1e3 / (int)1e2);
	printf("ʮλ   : %lld\n", integer % (int)1e2 / (int)1e1);
	printf("Բ     : %lld\n", integer % 10);
	
	//��ӡС������
	//ͨ����λȡ����������������������λС�������
	int digit_1 = (int)(decimal * 10);       //С����һλ
	int digit_2 = (int)(decimal * 100) % 10; //С���ڶ�λ
	int digit_3 = (int)(decimal * 1000) % 10;//С������λ ֻ������0����9
	printf("��     : %d\n", (((digit_2 + digit_3) / 10 + digit_2) / 10 + digit_1) % 10);
	printf("��     : %d\n", (((digit_2 + digit_3) / 10 + digit_2) % 10));

	return 0;
}
