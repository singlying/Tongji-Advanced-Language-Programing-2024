
#include<iostream>
#include <cmath>
using namespace std;

int main() 
{
	cout << "����������ֵ��" << endl;

	double num; //Ǯ��
	int count = 0; //����
	cin >> num;

	//��ȡ�������ֺ�С������
	int integer = (int)num;  //����ֵ
	double decimal = num - integer;
	int digit_1 = (int)(round((num - floor(num)) * 100)) / 10 % 10;
	int digit_2 = (int)(round((num - floor(num)) * 100)) % 10;
	int int_decimal = digit_1 * 10 + digit_2;  //С��ֵ

	int yuan_50 = 0, yuan_20 = 0, yuan_10 = 0, yuan_5 = 0, yuan_1 = 0,
		jiao_5 = 0, jiao_1 = 0, fen_5 = 0, fen_2 = 0, fen_1 = 0;

	//��������
	if (yuan_50 = integer / 50) {
		integer %= 50;
		count += yuan_50;
	}

	if (yuan_20 = integer / 20) {
		integer %= 20;
		count += yuan_20;
	}

	if (yuan_10 = integer / 10) {
		integer %= 10;
		count += yuan_10;
	}

	if (yuan_5 = integer / 5) {
		integer %= 5;
		count += yuan_5;
	}

	if (yuan_1 = integer) {
		count += yuan_1;
	}

	//С������
	if (jiao_5 = int_decimal / 50) {
		int_decimal %= 50;
		count += jiao_5;
	}

	if (jiao_1 = int_decimal / 10) {
		int_decimal %= 10;
		count += jiao_1;
	}

	if (fen_5 = int_decimal / 5) {
		int_decimal %= 5;
		count += fen_5;
	}

	if (fen_2 = int_decimal / 2) {
		int_decimal %= 2;
		count += fen_2;
	}

	if (fen_1 = int_decimal) {
		count += fen_1;
	}

	cout << "��" << count << "�����㣬�������£�" << endl;
	if (yuan_50) {
		cout << "50Ԫ : " << yuan_50 << "��" << endl;
	}

	if (yuan_20) {
		cout << "20Ԫ : " << yuan_20 << "��" << endl;
	}

	if (yuan_10) {
		cout << "10Ԫ : " << yuan_10 << "��" << endl;
	}

	if (yuan_5) {
		cout << "5Ԫ  : " << yuan_5 << "��" << endl;
	}

	if (yuan_1) {
		cout << "1Ԫ  : " << yuan_1 << "��" << endl;
	}

	if (jiao_5) {
		cout << "5��  : " << jiao_5 << "��" << endl;
	}

	if (jiao_1) {
		cout << "1��  : " << jiao_1 << "��" << endl;
	}

	if (fen_5) {
		cout << "5��  : " << fen_5 << "��" << endl;
	}

	if (fen_2) {
		cout << "2��  : " << fen_2 << "��" << endl;
	}

	if (fen_1) {
		cout << "1��  : " << fen_1 << "��" << endl;
	}

	return 0;
}