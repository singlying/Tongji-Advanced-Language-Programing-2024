
#include<iostream>
#include <cmath>
using namespace std;

int main()
{

	cout << "������[0-100��)֮�������:" << endl;

	double num;
	cin >> num;

	//��ȡ�������ֺ�С������
	long long integer = (long long)num;
	double decimal = num - integer;

	//��������
	int int_10 = (int) (integer / (int)1e9);
	int int_9 = integer % (int)1e9 / (int)1e8;
	int int_8 = integer % (int)1e8 / (int)1e7;
	int int_7 = integer % (int)1e7 / (int)1e6;
	int int_6 = integer % (int)1e6 / (int)1e5;
	int int_5 = integer % (int)1e5 / (int)1e4;
	int int_4 = integer % (int)1e4 / (int)1e3;
	int int_3 = integer % (int)1e3 / (int)1e2;
	int int_2 = integer % (int)1e2 / (int)1e1;
	int int_1 = integer % 10;
	//С������
	int digit_1 = (int)(round((num - floor(num)) * 100)) / 10 % 10;
	int digit_2 = (int)(round((num - floor(num)) * 100)) % 10;

	//������
	cout << "��д�����:" << endl;

	if (int_10) {  //ʮ��λ
		switch (int_10) {
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "ʰ";
	}


	if (int_9) { //��λ
		switch (int_9) {
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
	}

	int yi = 0; //��������������
	if (int_10 || int_9) { //��,ʮ�ڷ���
		cout << "��";
		yi = 1;
	}

	//��λ
	if (int_8) { //ǧ��
		switch (int_8) {
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "Ǫ";
	}
	else { //�ж������
		if (yi && (int_7 || int_6 || int_5)) {
			cout << "��";
		}
	}

	if (int_7) { //����
		switch (int_7) {
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "��";
	}
	else {
		if (int_8 && (int_6 || int_5)) {
			cout << "��";
		}
	}

	if (int_6) { //ʮ��
		switch (int_6) {
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "ʰ";
	}
	else {
		if (int_7 && int_5) {
			cout << "��";
		}
	}

	if (int_5) {  //��
		switch (int_5) {
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
	}

	int wan = 0;
	if (int_8 || int_7 || int_6 || int_5) {
		cout << "��";
		wan = 1;
	}

	//��λ
	if (int_4) { //ǧ
		switch (int_4) {
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "Ǫ";
	}
	else { //�ж������
		if ((yi || wan) && (int_3 || int_2 || int_1)) {
			cout << "��";
		}
	}

	if (int_3) { //��
		switch (int_3) {
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "��";
	}
	else {
		if (int_4 && (int_2 || int_1)) {
			cout << "��";
		}
	}

	if (int_2) { //ʮ
		switch (int_2) {
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "ʰ";
	}
	else {
		if (int_3 && int_1) {
			cout << "��";
		}
	}

	if (int_1) {  //��
		switch (int_1) {
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
	}

	//��� Ԫ
	int yuan = 0;
	if (int_1 || int_2 || int_3 || int_4 || int_5 || int_6 || int_7 || int_8 || int_9 || int_10) {
		cout << "Բ";
		yuan = 1;
		if (!digit_1 && !digit_2) {
			cout << "��";
		}
	}
	else if (!(int_1 || int_2 || int_3 || int_4 || int_5 || int_6 || int_7 || int_8 || int_9 || int_10 || digit_1 || digit_2)) { //�����Ԫ
		cout << "��Բ��";
	}

	//�Ƿ�
	if (digit_1) {
		switch (digit_1) {
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "��";
		if (!digit_2) {
			cout << "��";
		}
	}
	else {
		if (yuan && digit_2) {
			cout << "��";
		}
	}

	if (digit_2) { //��
		switch (digit_2) {
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		cout << "��";
	}

	cout << endl;

	return 0;
}