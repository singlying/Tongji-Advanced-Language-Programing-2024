
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int matrix[9][9];
	bool is_sudo = 1;

	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;

	//����
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			while (1) {
				cin >> matrix[i][j];

				if (cin.fail()) { //cin����
					cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
					cin.clear();
					cin.ignore(1024, '\n');
				}
				else if (matrix[i][j] > 9 || matrix[i][j] < 1) { //��Χ����
					cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
					continue;
				}
				else
					break;
			}
		}
	}

	//�ж���
	for (int i = 0; i < 9; i++) {
		int arr[9] = { 0 };
		for (int j = 0; j < 9; j++) {
			if (!arr[matrix[i][j] - 1])
				arr[matrix[i][j] - 1] = 1;
			else
				is_sudo = 0;
		}
	}

	//�ж���
	for (int i = 0; i < 9; i++) {
		int arr[9] = { 0 };
		for (int j = 0; j < 9; j++) {
			if (!arr[matrix[j][i] - 1])
				arr[matrix[j][i] - 1] = 1;
			else
				is_sudo = 0;
		}
	}

	//�жϷ���
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

	cout << (is_sudo ? "��" : "����") << "�����Ľ�" << endl;

	return 0;
}