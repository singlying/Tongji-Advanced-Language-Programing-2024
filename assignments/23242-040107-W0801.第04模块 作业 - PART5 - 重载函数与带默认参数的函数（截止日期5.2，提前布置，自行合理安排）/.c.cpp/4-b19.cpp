
#include<iostream>
using namespace std;

int min(int a, int b, int c = INT_MAX, int d = INT_MAX)
{
	int temp_1 = a < b ? a : b;
	int temp_2 = temp_1 < c ? temp_1 : c;
	return temp_2 < d ? temp_2 : d;
}

int main()
{
	int choose;
	int a = INT_MAX, b = INT_MAX, c = INT_MAX, d = INT_MAX;
	bool tag = 0;


	while (!tag) {
		cout << "���������num��num����������" << endl;
		while (1) {

			cin >> choose;
			if (cin.fail()) { //choose�������
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "���������num��num����������" << endl;
			}
			else if (choose < 2 || choose > 4) { //choose��Χ����
				cout << "�����������" << endl;
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
		if (cin.fail() || a < 1 || b < 1 || c < 1 || d < 1) { //�������
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else {
			tag = 1;
			break;
		}
	}

	cout << "min=" << min(a, b, c, d) << endl;

	return 0;
}