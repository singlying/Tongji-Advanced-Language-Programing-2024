
#include <iostream>
#include <iomanip>
using namespace std;

//��������ת��Ϊ����
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

//�ж�����
bool is_leap_year(int year)
{
	bool leap_year = 1;
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0)
				leap_year = 1;
			else
				leap_year = 0;
		}
	}
	else
		leap_year = 0;

	return leap_year;
}

//��ӡ��ͷ
void print_table(int i) //iΪ�ڼ������ ��һ��4����� 0 ~ 3
{
	i = i * 3 + 1;
	cout << endl << "           " << right << setw(2) << i << "��" << "                            " << setw(2)
		<< i + 1 << "��" << "                            " << setw(2) << i + 2 << "��" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
}

//��ӡ��i�ֵ�3���·�
void print_month(int year, int i)
{
	const int month_day[13] = {0,31,28 + is_leap_year(year),31,30,31,30,31,31,30,31,30,31 }; //��¼�·ݵ�����
	int day_pointer[13]; //ÿ��������ָ��  ��Χ1 ~ month_day[i]  ��ʾҪ��һ��Ҫ�����һ��
	int start_day[13] = { 0 };

	for (int i = 0; i < 13; i++) //��ʼ��Ϊ1
		day_pointer[i] = 1;

	for (int i = 1; i < 13; i++) {
		start_day[i] = zeller(year, i, 1);
	}

	print_table(i);

	int start_month = i * 3 + 1; //��ʼ�·�
	int now_month = start_month; //��ǰ�·�


	while (day_pointer[start_month] <= month_day[start_month] || day_pointer[start_month + 1] <=
		month_day[start_month + 1] || day_pointer[start_month + 2] <= month_day[start_month + 2]) {
		while (now_month < i * 3 + 4) {
			if (day_pointer[now_month] == 1) //����տ�ʼ�������µ�day
				for (int i = 0; i < start_day[now_month]; i++) { //�����ʼ�Ŀո�
					cout << "    ";
				}

			if (day_pointer[now_month] > month_day[now_month]) { //������Ѿ������
				cout << setw(4 * 8) << " ";
				now_month++;
				continue;
			}

			//���day
			while (day_pointer[now_month] <= month_day[now_month]) {
				//cout << setiosflags(ios::left) << setw(4) << day_pointer[now_month];
				cout << left << setw(4) << day_pointer[now_month];
				if ((start_day[now_month] + day_pointer[now_month]) % 7 == 0) {
					day_pointer[now_month]++;
					break;
				}
				day_pointer[now_month]++;
			}

			if (now_month % 3) //�·��м�Ŀո�  4 +   
				cout << setw(4 + 4 * ((7 - (start_day[now_month] + day_pointer[now_month] - 1) % 7) % 7)) << " ";
			else if (now_month % 3 == 0 && (day_pointer[start_month] <= month_day[start_month] || day_pointer[start_month + 1] <=
				month_day[start_month + 1] || day_pointer[start_month + 2] <= month_day[start_month + 2]))
				cout << endl;

			now_month++;
		}

		now_month = start_month;
	}
}

int main()
{
	int year;
	cout << "���������[1900-2100]" << endl;
	cin >> year;
	cout << year << "�������:" << endl;

	for (int i = 0; i < 4; i++) {
		print_month(year, i);
		cout << endl;
	}

	cout << endl << endl;

	return 0;
}