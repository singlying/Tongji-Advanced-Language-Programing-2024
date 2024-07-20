
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	printf("请输入[0-100 亿)之间的数字:\n");

	double num;	
	scanf("%lf", &num);
	     
	//提取整数部分和小数部分
	long long integer = (long long)num;
	double decimal = num - integer;
	
	//打印整数部分
	printf("十亿位 : %lld\n", integer / (int)1e9);
	printf("亿位   : %lld\n", integer % (int)1e9 / (int)1e8);
	printf("千万位 : %lld\n", integer % (int)1e8 / (int)1e7);
	printf("百万位 : %lld\n", integer % (int)1e7 / (int)1e6);
	printf("十万位 : %lld\n", integer % (int)1e6 / (int)1e5);
	printf("万位   : %lld\n", integer % (int)1e5 / (int)1e4);
	printf("千位   : %lld\n", integer % (int)1e4 / (int)1e3);
	printf("百位   : %lld\n", integer % (int)1e3 / (int)1e2);
	printf("十位   : %lld\n", integer % (int)1e2 / (int)1e1);
	printf("圆     : %lld\n", integer % 10);
	
	//打印小数部分
	//通过进位取余运算消除误差，仅适用于两位小数的情况
	int digit_1 = (int)(decimal * 10);       //小数第一位
	int digit_2 = (int)(decimal * 100) % 10; //小数第二位
	int digit_3 = (int)(decimal * 1000) % 10;//小数第三位 只可能是0或者9
	
	
	digit_1 = (int)(round((decimal - floor(decimal)) * 100)) / 10 % 10;
	digit_2 = (int)(round((decimal - floor(decimal)) * 100)) % 10;
	
	
	printf("%d %d\n", digit_1, digit_2);
	
	//printf("角     : %d\n", (((digit_2 + digit_3) / 10 + digit_2) / 10 + digit_1) % 10);
	//printf("分     : %d\n", (((digit_2 + digit_3) / 10 + digit_2) % 10));



	/*double a = 1.23;
	double b = a - 1;
	int i_1 = (int)(b * 10.0);
	int i_2 = (int)(b * 100.0f) % 10;
	int i_3 = (int)(b * 1000.0f) % 10;
	
	printf("%f\n", b);
	printf("%d %d %d\n", i_1, i_2, i_3);
	printf("%d %d", (int)(b * 100.0) / 10, (int)(b * 1000.0) / 10);*/
	
	return 0;
}
