
#include<iostream>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int max(int a, int b, int c)
{
	return (a > b ? a : b) > c ? (a > b ? a : b) : c;
}

int max(int a, int b, int c, int d)
{
	int temp_1 = a > b ? a : b;
	int temp_2 = temp_1 > c ? temp_1 : c;
	return temp_2 > d ? temp_2 : d;
}

int main()
{
	int choose;
	int a = 1, b = 1, c = 1, d = 1;  //初值为1，方便后续检验正整数
	bool tag = 0;


	while (!tag) {
		cout << "请输入个数num及num个正整数：" << endl;
		while (1) {
			
			cin >> choose;
			if (cin.fail()) { //choose输入错误
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "请输入个数num及num个正整数：" << endl;
			}
			else if (choose < 2 || choose > 4) { //choose范围错误
				cout << "个数输入错误" << endl;
				cin.ignore(1024, '\n');
				return 0;
			}
			else
				break;
		}

		switch (choose) {
			case 2:
				cin >> a >> b;
				break;
			case 3:
				cin >> a >> b >> c;
				break;
			case 4:
				cin >> a >> b >> c >> d;
				break;
		}
		if (cin.fail() || a < 1 || b < 1 || c < 1 || d < 1) { //输入错误
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else {
			tag = 1;
			break;
		}
	}

	switch (choose) {
		case 2:
			cout << "max=" << max(a, b) << endl;
			break;
		case 3:
			cout << "max=" << max(a, b, c) << endl;
			break;
		case 4:
			cout << "max=" << max(a, b, c, d) << endl;
			break;
	}


	return 0;
}