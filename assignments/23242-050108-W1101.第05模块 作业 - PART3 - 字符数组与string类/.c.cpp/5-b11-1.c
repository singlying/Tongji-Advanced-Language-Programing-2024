
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//可按需增加需要的头文件

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/
int fun(int num, int i)  //输出大写数字
{
	result[i++] = chnstr[num * 2];
	result[i++] = chnstr[num * 2 + 1];
	return i;
}


int main()
{
	printf("请输入[0-100亿)之间的数字:\n");

	double num;
	scanf("%lf", &num);
	int arr[12];

	//提取整数部分和小数部分
	long long integer = (long long)num;
	double decimal = num - integer + 0.001;

	//整数部分
	for (int i = 9; i >= 0; i--) {
		arr[i] = integer % 10;
		integer /= 10;
	}
	//小数部分
	arr[10] = (int)(decimal * 10);
	arr[11] = (int)(decimal * 100) % 10;

	int i = 0;

	if (arr[0]) { //十亿位
		i = fun(arr[0], i);
		sprintf(result + i, "拾");
		i += 2;  //GB汉字编码占2个字符
	}

	if (arr[1]) { //亿位
		i = fun(arr[1], i);
	}

	int yi = 0; //代表亿上有数字
	if (arr[0] || arr[1]) { //亿,十亿非零
		sprintf(result + i, "亿");
		yi = 1;
		i += 2;
	}

	//万位
	if (arr[2]) {  //千万
		i = fun(arr[2], i);
		sprintf(result + i, "仟");
		i += 2;
	}
	else { //判断输出零
		if (yi && (arr[3] || arr[4] || arr[5])) {
			i = fun(0, i);
		}
	}

	if (arr[3]) { //百万
		i = fun(arr[3], i);
		sprintf(result + i, "佰");
		i += 2;
	}
	else {
		if (arr[2] && (arr[4] || arr[5])) {
			i = fun(0, i);
		}
	}

	if (arr[4]) { //十万
		i = fun(arr[4], i);
		sprintf(result + i, "拾");
		i += 2;
	}
	else {
		if (arr[3] && arr[5]) {
			i = fun(0, i);
		}
	}

	if (arr[5]) {  //万
		i = fun(arr[5], i);
	}

	int wan = 0;
	if (arr[2] || arr[3] || arr[4] || arr[5]) {
		sprintf(result + i, "万");
		i += 2;
		wan = 1;
	}

	//个位
	if (arr[6]) { //千
		i = fun(arr[6], i);
		sprintf(result + i, "仟");
		i += 2;
	}
	else { //判断输出零
		if ((yi || wan) && (arr[7] || arr[8] || arr[9])) {
			i = fun(0, i);
		}
	}

	if (arr[7]) { //百
		i = fun(arr[7], i);
		sprintf(result + i, "佰");
		i += 2;
	}
	else {
		if (arr[6] && (arr[8] || arr[9])) {
			i = fun(0, i);
		}
	}

	if (arr[8]) { //十
		i = fun(arr[8], i);
		sprintf(result + i, "拾");
		i += 2;
	}
	else {
		if (arr[7] && arr[9]) {
			i = fun(0, i);
		}
	}

	if (arr[9]) {  //个
		i = fun(arr[9], i);
	}

	//输出 元
	int yuan = 0;
	if (arr[9] || arr[8] || arr[7] || arr[6] || wan || yi) {
		sprintf(result + i, "圆");
		i += 2;
		yuan = 1;
		if (!arr[10] && !arr[11]) {
			sprintf(result + i, "整");
			i += 2;
		}
	}
	else if (!(arr[9] || arr[8] || arr[7] || arr[6] || wan || yi || arr[10] || arr[11])) { //输出零元
		i = fun(0, i);
		sprintf(result + i, "圆整");
		i += 2;
	}

	//角分
	if (arr[10]) { //角
		i = fun(arr[10], i);
		sprintf(result + i, "角");
		i += 2;
		if (!arr[11]) {
			sprintf(result + i, "整");
			i += 2;
		}
	}
	else {
		if (yuan && arr[11]) {
			i = fun(0, i);
		}
	}

	if (arr[11]) { //分
		i = fun(arr[11], i);
		sprintf(result + i, "分");
		i += 2;
	}

	//输出结果
	printf("大写结果是:\n");
	printf("%s\n", result);  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
	return 0;
}
