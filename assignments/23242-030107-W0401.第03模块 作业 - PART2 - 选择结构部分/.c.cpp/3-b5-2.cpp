
#include<iostream>
using namespace std;

#define day_1 31
#define day_2 30
#define day_3 28

int main()
{
	cout << "�������꣬�£���" << endl;
	int year, month, day;
	cin >> year >> month >> day;

	//�ж��·ݺϷ�  
	if (month > 12 || month < 1) {
		cout << "�������-�·ݲ���ȷ" << endl;
		return 0;
	}

	int leap_year = -1;
	//�ж�����
	if (year % 4 == 0) {
		leap_year = 1;
		if (year % 100 == 0) {
			if (year % 400 == 0)
				leap_year = 1;
			else
				leap_year = 0;
		}
	}
	else
		leap_year = 0;

	//�ж����ںϷ�
	if (day < 1) { //����
		cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
		return 0;
	}

	switch (month) { //����
	case 2:
		if (leap_year && day > 29) {
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			return 0;
		}
		else if (!leap_year && day > 28) {
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			return 0;
		}
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day > 31) {
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			return 0;
		}
		break;
	default:
		if (day > 30) {
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			return 0;
		}
		break;
	}

	//�ڼ���
	int count = 0;
	switch (month) {
	case 1:
		count = day;
		break;
	case 2:
		count = day_1 + day;
		break;
	case 3:
		count = day_1 + day_3 + leap_year + day;
		break;
	case 4:
		count = day_1 * 2 + day_3 + leap_year + day;
		break;
	case 5:
		count = day_1 * 2 + day_2 + day_3 + leap_year + day;
		break;
	case 6:
		count = day_1 * 3 + day_2 + day_3 + leap_year + day;
		break;
	case 7:
		count = day_1 * 3 + day_2 * 2 + day_3 + leap_year + day;
		break;
	case 8:
		count = day_1 * 4 + day_2 * 2 + day_3 + leap_year + day;
		break;
	case 9:
		count = day_1 * 5 + day_2 * 2 + day_3 + leap_year + day;
		break;
	case 10:
		count = day_1 * 5 + day_2 * 3 + day_3 + leap_year + day;
		break;
	case 11:
		count = day_1 * 6 + day_2 * 3 + day_3 + leap_year + day;
		break;
	case 12:
		count = day_1 * 6 + day_2 * 4 + day_3 + leap_year + day;
		break;
	}

	cout << year << '-' << month << '-' << day << "��" << year << "��ĵ�" << count << "��" << endl;

	return 0;
}