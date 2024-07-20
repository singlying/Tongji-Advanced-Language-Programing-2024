
#include <iostream>
using namespace std;

int zeller(int y, int m, int d)
{
	if (m <= 2) {
		m += 12;
		y--;
	}
	int c = y / 100;
	y %= 100;

	int w = y + y / 4 + c / 4 - 2 * c + (13 * (m + 1) / 5) + d - 1;

	return (w % 7 + 7) % 7;
}

int main()
{
	int year, month, day;
	int leap_year = 0;
	while (1) {
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> year >> month >> day;
		if (cin.fail()) {
			cout << "�����������������" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (year < 1900 || year > 2100) { //�ж����
			cout << "��ݲ���ȷ������������" << endl;
			continue;
		}
		else { //�ж�����
			if (year % 4 == 0) {
				leap_year = 1;
				if (year % 100 == 0) {
					leap_year = 0;
					if (year % 400 == 0)
						leap_year = 1;
				}
			}
			else
				leap_year = 0;
		}

		if (month > 12 || month < 1) { //�ж��·�
			cout << "�·ݲ���ȷ������������" << endl;
			continue;
		}

		if (month == 1 || month == 3 || month == 5 || month == 7 ||
			month == 8 || month == 10 || month == 12) { //�ж�����
			if (day > 31 || day < 1) {
				cout << "�ղ���ȷ������������" << endl;
				continue;
			}
		}
		else if (month == 2) {
			if (leap_year && (day > 29 || day < 1)) {
				cout << "�ղ���ȷ������������" << endl;
				continue;
			}
			else if (!leap_year && (day > 28 || day < 1)) {
				cout << "�ղ���ȷ������������" << endl;
				continue;
			}
		}
		else {
			if (day > 30 || day < 1) {
				cout << "�ղ���ȷ������������" << endl;
				continue;
			}
		}

		break;
	}

	int week = zeller(year, month, day);
	switch (week)
	{
		case 0:
			cout << "������" << endl;
			break;
		case 1:
			cout << "����һ" << endl;
			break;
		case 2:
			cout << "���ڶ�" << endl;
			break;
		case 3:
			cout << "������" << endl;
			break;
		case 4:
			cout << "������" << endl;
			break;
		case 5:
			cout << "������" << endl;
			break;
		case 6:
			cout << "������" << endl;
			break;
	}

	return 0;
}