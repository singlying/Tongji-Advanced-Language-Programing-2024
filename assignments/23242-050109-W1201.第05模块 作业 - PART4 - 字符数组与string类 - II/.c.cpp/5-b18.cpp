
#include <iostream>
#include <ctime>
using namespace std;

#define SUM 10
static const char other[] = "!@#$%^&*-_=+,.?";
//辅助检测other[]
bool test(char ch)
{
	for (int i = 0; i < sizeof(other) - 1; i++)
		if (ch == other[i])
			return true;
	return false;
}
//主要检测函数
bool fun(const char arr[], const int len, const int upper_case, const int lower_case, const int number, const int other_num)
{
	int test_len = 0;
	int test_upper = 0, test_lower = 0, test_number = 0, test_other = 0;

	int j = 0;
	char ch;
	while ((ch = arr[j]) != '\0') {
		if (ch <= 'Z' && ch >= 'A')
			test_upper++;
		else if (ch <= 'z' && ch >= 'a')
			test_lower++;
		else if (ch <= '9' && ch >= '0')
			test_number++;
		else if (test(ch))
			test_other++;
		j++;
	}

	test_len = test_lower + test_upper + test_number + test_other;

	if (test_len != len || test_upper < upper_case || test_lower < lower_case
		|| test_number < number || test_other < other_num)
		return false;
	else
		return true;
}

int main()
{
	cin.ignore(1024, '\n'); //忽略第一行

	int len;
	int upper_case, lower_case, number, other_num;
	char arr[10][17];

	cin >> len >> upper_case >> lower_case >> number >> other_num;

	//输入错误
	if (cin.fail() || len > 16 || len < 12
		|| upper_case < 2 || lower_case < 2
		|| number < 2 || other_num < 2
		|| len < (upper_case + lower_case + number + other_num)) {
		cout << "错误" << endl;
		return 0;
	}
	else
		cin.ignore(1024, '\n');

	//输入
	//char a = getchar(); //去除缓冲区的换行符
	for (int i = 0; i < SUM; i++) {  

		int j = 0;
		char ch;
		while ((ch = getchar()) != '\n' && j < 17) {   //判断如果多输入，则直接报错返回 避免爆栈
			arr[i][j] = ch;
			j++;
		}
		if (j == 17) {
			cout << "错误" << endl;
			return 0;
		}
		arr[i][j] = '\0';
	}


	bool tag = true;
	for (int i = 0; i < SUM; i++) {
		if (!fun(arr[i], len, upper_case, lower_case, number, other_num))
			tag = false;
	}

	cout << (tag ? "正确" : "错误") << endl;

	return 0;
}