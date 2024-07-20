
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("请输入一个[1..30000]间的整数:\n");

	unsigned int a;

	scanf("%u", &a);

	printf("万位 : %d\n", w);

	a = a % 10000;
	printf("千位 : %d\n", q);

	a = a % 1000;
	printf("百位 : %d\n", b);

	a = a % 100;
	printf("十位 : %d\n", s);

	a = a % 10;
	printf("个位 : %d", g);

	return 0;
}