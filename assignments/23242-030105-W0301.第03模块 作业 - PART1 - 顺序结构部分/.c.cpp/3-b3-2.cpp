
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "������[0-100 ��)֮�������:" << endl;

	double num;
	cin >> num;

	//��ȡ�������ֺ�С������
	long long integer = (long long)num;
	double decimal = num - integer;

	//��ӡ��������
	cout << "ʮ��λ : " << integer / int(1e9) << endl;
	cout << "��λ   : " << integer % int(1e9) / int(1e8) << endl;
	cout << "ǧ��λ : " << integer % int(1e8) / int(1e7) << endl;
	cout << "����λ : " << integer % int(1e7) / int(1e6) << endl;
	cout << "ʮ��λ : " << integer % int(1e6) / int(1e5) << endl;
	cout << "��λ   : " << integer % int(1e5) / int(1e4) << endl;
	cout << "ǧλ   : " << integer % int(1e4) / int(1e3) << endl;
	cout << "��λ   : " << integer % int(1e3) / int(1e2) << endl;
	cout << "ʮλ   : " << integer % int(1e2) / int(1e1) << endl;
	cout << "Բ     : " << integer % 10 << endl;

	//��ӡС������
	//ͨ����λȡ����������������������λС�������
	int digit_1 = int(decimal * 10);       //С����һλ
	int digit_2 = int(decimal * 100) % 10; //С���ڶ�λ
	int digit_3 = int(decimal * 1000) % 10;//С������λ ֻ������0����9
	cout << "��     : " << (((digit_2 + digit_3) / 10 + digit_2) / 10 + digit_1) % 10 << endl;
	cout << "��     : " << (((digit_2 + digit_3) / 10 + digit_2) % 10) << endl;


	return 0;
}