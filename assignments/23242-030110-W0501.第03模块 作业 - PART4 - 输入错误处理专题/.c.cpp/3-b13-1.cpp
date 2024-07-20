
#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
	int year, month, start_day; //�꣬�£�����

	//����
	while (1) {
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> year;
		cin >> month;

		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (year <= 2030 && year >= 2000 && month >= 1 && month <= 12) {
			break;
		}

		cout << "����Ƿ�������������" << endl;
	}

	while (1) {
		cout << "������" << year << "��" << month << "��1�յ�����(0-6��ʾ������-������) : "; //����ط�û�л��з�
		cin >> start_day;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (start_day >= 0 && start_day <= 6) {
			break;
		}

		cout << "����Ƿ�������������" << endl;
	}

	//�ж�����
	int leap_year = -1;
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

	//��ӡ
	cout << endl << year << "��" << month << "�µ�����Ϊ:" << endl; //����ط��ʼ��һ�����з�
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;

	for (int i = 0; i < start_day; i++) { //��ʼ�Ŀո�
		cout << "        ";
	}

	int meta_day = 0; //���������·ݵ�����

	int day_num = 1; //��ǰ����

	//����meta_day
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) { //1 3 5 7 8 10 12��
		meta_day = 3;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) { //4 6 9 11��
		meta_day = 2;
	}
	else if (month == 2 && leap_year) { //��2��
		meta_day = 1;
	}

	while (day_num <= 28 + meta_day) {
		cout << setw(4) << day_num << "    ";
		if ((start_day + day_num) % 7 == 0) {
			cout << endl;
		}
		day_num++;
	}

	cout << endl;

	return 0;
}