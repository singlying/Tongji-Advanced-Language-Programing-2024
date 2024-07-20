
#include <iostream>
using namespace std;

/* �ɸ�����Ҫ������Ӧ������ */

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������num_���� flag_��ʶ��
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* �������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
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
		default:
			cout << "error";
			break;
	}
}

int main()
{
	cout << "������[0-100��)֮�������:" << endl;

	double num;
	cin >> num;

	//��ȡ�������ֺ�С������
	long long integer = (long long)num;
	double decimal = num - integer + 0.001; ////

	//��������
	int int_10 = (int)(integer / (int)1e9);
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
	int digit_1 = (int)(decimal * 10);
	int digit_2 = (int)(decimal * 100) % 10;

	//������
	cout << "��д�����:" << endl;

	if (int_10) { //ʮ��λ
		daxie(int_10, 0);
		cout << "ʰ";
	}

	if (int_9) { //��λ
		daxie(int_9, 0);
	}

	int yi = 0; //��������������
	if (int_10 || int_9) { //��,ʮ�ڷ���
		cout << "��";
		yi = 1;
	}

	//��λ
	if (int_8) { //ǧ��
		daxie(int_8, 0);
		cout << "Ǫ";
	}
	else { //�ж������
		if (yi && (int_7 || int_6 || int_5)) {
			daxie(0, 1);
		}
	}

	if (int_7) { //����
		daxie(int_7, 0);
		cout << "��";
	}
	else {
		if (int_8 && (int_6 || int_5)) {
			daxie(0, 1);
		}
	}

	if (int_6) { //ʮ��
		daxie(int_6, 0);
		cout << "ʰ";
	}
	else {
		if (int_7 && int_5) {
			daxie(0, 1);
		}
	}

	if (int_5) {  //��
		daxie(int_5, 0);
	}

	int wan = 0;
	if (int_8 || int_7 || int_6 || int_5) {
		cout << "��";
		wan = 1;
	}

	//��λ
	if (int_4) { //ǧ
		daxie(int_4, 0);
		cout << "Ǫ";
	}
	else { //�ж������
		if ((yi || wan) && (int_3 || int_2 || int_1)) {
			daxie(0, 1);
		}
	}

	if (int_3) { //��
		daxie(int_3, 0);
		cout << "��";
	}
	else {
		if (int_4 && (int_2 || int_1)) {
			daxie(0, 1);
		}
	}

	if (int_2) { //ʮ
		daxie(int_2, 0);
		cout << "ʰ";
	}
	else {
		if (int_3 && int_1) {
			daxie(0, 1);
		}
	}

	if (int_1) {  //��
		daxie(int_1, 0);
	}

	//��� Ԫ
	int yuan = 0;
	if (int_1 || int_2 || int_3 || int_4 || wan || yi) {
		cout << "Բ";
		yuan = 1;
		if (!digit_1 && !digit_2) {
			cout << "��";
		}
	}
	else if (!(int_1 || int_2 || int_3 || int_4 || wan || yi || digit_1 || digit_2)) { //�����Ԫ
		daxie(0, 1);
		cout << "Բ��";
	}

	//�Ƿ�
	if (digit_1) { //��
		daxie(digit_1, 0);
		cout << "��";
		if (!digit_2) {
			cout << "��";
		}
	}
	else {
		if (yuan && digit_2) {
			daxie(0, 1);
		}
	}

	if(digit_2) { //��
		daxie(digit_2, 0);
		cout << "��";
	}

	cout << endl;

	return 0;
}
