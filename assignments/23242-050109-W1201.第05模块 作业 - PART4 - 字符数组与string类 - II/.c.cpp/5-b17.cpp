
#include <iostream>
#include <ctime>
using namespace std;

#define SUM 10
static const char other[] = "!@#$%^&*-_=+,.?";

//生成密码
void generator(char arr[], int len, int upper_case, int lower_case, int number, int other_num)
{	
	int left_num = len - upper_case - lower_case - number - other_num;

	int random_num[4] = { upper_case, lower_case, number, other_num };

	//把余下的自由分配的char数量随机分配
	for (int i = 0; i < left_num; i++) {
		random_num[rand() % 4]++;
	}

	//i顺序过一遍位置，对4种类型数据随机取样，如果该类型不满就加入
	for (int i = 0; i < len; i++) {
		int choise = rand() % 4;
		if (random_num[choise]) {
			random_num[choise]--;
			switch (choise) {
				case 0: //upper_case
					arr[i] = rand() % 26 + 'A';
					break;
				case 1: //lower_case
					arr[i] = rand() % 26 + 'a';
					break;
				case 2: //number
					arr[i] = rand() % 10 + '0';
					break;
				case 3: //other
					arr[i] = other[rand() % 15];
					break;
			}
		}
		else
			i--;
	}

	//arr[len] = '\0';
}

int main()
{
	srand((unsigned)time(NULL));
	int len;
	int upper_case, lower_case, number, other_num;
	char arr[10][17];

	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;

	cin >> len >> upper_case >> lower_case >> number >> other_num;

	//判断输入正确
	if (cin.fail()) {
		cout << "输入非法" << endl;
		return 0;
	}
	else if (len > 16 || len < 12) {
		cout << "密码长度[" << len << "]不正确" << endl;
		return 0;
	}
	else if (upper_case < 2) {
		cout << "大写字母个数[" << upper_case << "]不正确" << endl;
		return 0;
	}
	else if (lower_case < 2) {
		cout << "小写字母个数[" << lower_case << "]不正确" << endl;
		return 0;
	}
	else if (number < 2) {
		cout << "数字个数[" << number << "]不正确" << endl;
		return 0;
	}
	else if (other_num < 2) {
		cout << "其它符号个数[" << other_num << "]不正确" << endl;
		return 0;
	}
	else if (len < (upper_case + lower_case + number + other_num)) {
		cout << "所有字符类型之和[" << upper_case << "+" << lower_case << "+" << number << "+" << other_num << "]大于总密码长度[" << len << "]" << endl;
		return 0;
	}

	//输出输入的数据
	cout << len << " " << upper_case << " " << lower_case << " " << number << " " << other_num << endl;

	//生成
	for (int i = 0; i < SUM; i++) {
		generator(arr[i], len, upper_case, lower_case, number, other_num);
		//arr[i][len] = '\0';
	}

	//输出
	for (int i = 0; i < SUM; i++)
	{
		for (int j = 0; j < len; j++)
			cout << arr[i][j];
		cout << endl;
	}

	return 0;
}