
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	printf("�����������ε����߼���н�(�Ƕ�)\n");

	int a, b, angle;
	const double Pi = 3.14159;
	scanf("%d %d %d", &a, &b, &angle);
	printf("���������Ϊ : %.3f\n", (float) (0.5 * a * b * sin(Pi * angle / 180)));

	return 0;
}