
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("请输入半径和高度\n");

	float r, h;
	scanf("%lf %lf", &r, &h);

	const float Pi = 3.14159f;

	printf("圆周长     : %.2lf\n", 2 * Pi * r);
	printf("圆面积     : %.2lf\n", Pi * r * r);
	printf("圆球表面积 : %.2lf\n", 4 * Pi * r * r);
	printf("圆球体积   : %.2lf\n", Pi * r * r * r * 4 / 3);
	printf("圆柱体积   : %.2lf", Pi * r * r * h);

	return 0;
}