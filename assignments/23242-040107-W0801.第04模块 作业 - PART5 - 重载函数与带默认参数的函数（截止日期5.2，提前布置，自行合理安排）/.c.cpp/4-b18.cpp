
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
	int a = 1, b = 1, c = 1, d = 1;  //��ֵΪ1�������������������
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