
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int matrix[9][9];
	bool is_sudo = 1;

	cout << "请输入9*9的矩阵，值为1-9之间" << endl;

	//输入
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			while (1) {
				cin >> matrix[i][j];

				if (cin.fail()) { //cin错误
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					cin.clear();
					cin.ignore(1024, '\n');
				}
				else if (matrix[i][j] > 9 || matrix[i][j] < 1) { //范围错误
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					continue;
				}
				else
					break;
			}
		}
	}

	//判断行
	for (int i = 0; i < 9; i++) {
		int arr[9] = { 0 };
		for (int j = 0; j < 9; j++) {
			if (!arr[matrix[i][j] - 1])
				arr[matrix[i][j] - 1] = 1;
			else
				is_sudo = 0;
		}
	}

	//判断列
	for (int i = 0; i < 9; i++) {
		int arr[9] = { 0 };
		for (int j = 0; j < 9; j++) {
			if (!arr[matrix[j][i] - 1])
				arr[matrix[j][i] - 1] = 1;
			else
				is_sudo = 0;
		}
	}

	//判断方块
	for (int i = 0; i < 9; i++) {
		int arr[9] = { 0 };
		for (int j = (i / 3) * 3; j < (i / 3) * 3 + 3; j++) {
			for (int k = (i % 3) * 3; k < (i % 3) * 3 + 3; k++) {
				if (!arr[matrix[j][k] - 1])
					arr[matrix[j][k] - 1] = 1;
				else
					is_sudo = 0;
			}
		}
	}

	cout << (is_sudo ? "是" : "不是") << "数独的解" << endl;

	return 0;
}