
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("������뾶�͸߶�\n");

	float r, h;
	scanf("%lf %lf", &r, &h);

	const float Pi = 3.14159f;

	printf("Բ�ܳ�     : %.2lf\n", 2 * Pi * r);
	printf("Բ���     : %.2lf\n", Pi * r * r);
	printf("Բ������ : %.2lf\n", 4 * Pi * r * r);
	printf("Բ�����   : %.2lf\n", Pi * r * r * r * 4 / 3);
	printf("Բ�����   : %.2lf", Pi * r * r * h);

	return 0;
}