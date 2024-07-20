
#include <iostream>
#include <string>
//可按需增加需要的头文件
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/
void fun(int num)  //输出大写数字
{
	result += string(&chnstr[num * 2], &chnstr[num * 2 + 2]);
}

int main()
{
	cout << "请输入[0-100亿)之间的数字:" << endl;

	double num;    //输入数据
	int arr[12];  //存储数据
	cin >> num;

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

	if (arr[0]) { //十亿位
		fun(arr[0]);
		result += "拾";
	}

	if (arr[1]) { //亿位
		fun(arr[1]);
	}

	int yi = 0; //代表亿上有数字
	if (arr[0] || arr[1]) { //亿,十亿非零
		result += "亿";
		yi = 1;
	}

	//万位
	if (arr[2]) {  //千万
		fun(arr[2]);
		result += "仟";
	}
	else { //判断输出零
		if (yi && (arr[3] || arr[4] || arr[5])) {
			fun(0);
		}
	}

	if (arr[3]) { //百万
		fun(arr[3]);
		result += "佰";
	}
	else {
		if (arr[2] && (arr[4] || arr[5])) {
			fun(0);
		}
	}

	if (arr[4]) { //十万
		fun(arr[4]);
		result += "拾";
	}
	else {
		if (arr[3] && arr[5]) {
			fun(0);
		}
	}

	if (arr[5]) {  //万
		fun(arr[5]);
	}
	
	int wan = 0;
	if (arr[2] || arr[3] || arr[4] || arr[5]) {
		result += "万";
		wan = 1;
	}

	//个位
	if (arr[6]) { //千
		fun(arr[6]);
		result += "仟";
	}
	else { //判断输出零
		if ((yi || wan) && (arr[7] || arr[8] || arr[9])) {
			fun(0);
		}
	}

	if (arr[7]) { //百
		fun(arr[7]);
		result += "佰";
	}
	else {
		if (arr[6] && (arr[8] || arr[9])) {
			fun(0);
		}
	}

	if (arr[8]) { //十
		fun(arr[8]);
		result += "拾";
	}
	else {
		if (arr[7] && arr[9]) {
			fun(0);
		}
	}

	if (arr[9]) {  //个
		fun(arr[9]);
	}

	//输出 元
	int yuan = 0;
	if (arr[9] || arr[8] || arr[7] || arr[6] || wan || yi) {
		result += "圆";
		yuan = 1;
		if (!arr[10] && !arr[11]) {
			result += "整";
		}
	}
	else if (!(arr[9] || arr[8] || arr[7] || arr[6] || wan || yi || arr[10] || arr[11])) { //输出零元
		fun(0);
		result += "圆整";
	}

	//角分
	if (arr[10]) { //角
		fun(arr[10]);
		result += "角";
		if (!arr[11]) {
			result += "整";
		}
	}
	else {
		if (yuan && arr[11]) {
			fun(0);
		}
	}

	if (arr[11]) { //分
		fun(arr[11]);
		result += "分";
	}

	//输出结果
	cout << "大写结果是:" << endl;
    cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}
  