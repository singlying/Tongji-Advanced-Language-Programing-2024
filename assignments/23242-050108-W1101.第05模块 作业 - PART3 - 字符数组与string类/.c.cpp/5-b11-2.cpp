
#include <iostream>
#include <string>
//�ɰ���������Ҫ��ͷ�ļ�
using namespace std;

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
void fun(int num)  //�����д����
{
	result += string(&chnstr[num * 2], &chnstr[num * 2 + 2]);
}

int main()
{
	cout << "������[0-100��)֮�������:" << endl;

	double num;    //��������
	int arr[12];  //�洢����
	cin >> num;

	//��ȡ�������ֺ�С������
	long long integer = (long long)num;
	double decimal = num - integer + 0.001;

	//��������
	for (int i = 9; i >= 0; i--) {
		arr[i] = integer % 10;
		integer /= 10;
	}
	//С������
	arr[10] = (int)(decimal * 10);
	arr[11] = (int)(decimal * 100) % 10;

	if (arr[0]) { //ʮ��λ
		fun(arr[0]);
		result += "ʰ";
	}

	if (arr[1]) { //��λ
		fun(arr[1]);
	}

	int yi = 0; //��������������
	if (arr[0] || arr[1]) { //��,ʮ�ڷ���
		result += "��";
		yi = 1;
	}

	//��λ
	if (arr[2]) {  //ǧ��
		fun(arr[2]);
		result += "Ǫ";
	}
	else { //�ж������
		if (yi && (arr[3] || arr[4] || arr[5])) {
			fun(0);
		}
	}

	if (arr[3]) { //����
		fun(arr[3]);
		result += "��";
	}
	else {
		if (arr[2] && (arr[4] || arr[5])) {
			fun(0);
		}
	}

	if (arr[4]) { //ʮ��
		fun(arr[4]);
		result += "ʰ";
	}
	else {
		if (arr[3] && arr[5]) {
			fun(0);
		}
	}

	if (arr[5]) {  //��
		fun(arr[5]);
	}
	
	int wan = 0;
	if (arr[2] || arr[3] || arr[4] || arr[5]) {
		result += "��";
		wan = 1;
	}

	//��λ
	if (arr[6]) { //ǧ
		fun(arr[6]);
		result += "Ǫ";
	}
	else { //�ж������
		if ((yi || wan) && (arr[7] || arr[8] || arr[9])) {
			fun(0);
		}
	}

	if (arr[7]) { //��
		fun(arr[7]);
		result += "��";
	}
	else {
		if (arr[6] && (arr[8] || arr[9])) {
			fun(0);
		}
	}

	if (arr[8]) { //ʮ
		fun(arr[8]);
		result += "ʰ";
	}
	else {
		if (arr[7] && arr[9]) {
			fun(0);
		}
	}

	if (arr[9]) {  //��
		fun(arr[9]);
	}

	//��� Ԫ
	int yuan = 0;
	if (arr[9] || arr[8] || arr[7] || arr[6] || wan || yi) {
		result += "Բ";
		yuan = 1;
		if (!arr[10] && !arr[11]) {
			result += "��";
		}
	}
	else if (!(arr[9] || arr[8] || arr[7] || arr[6] || wan || yi || arr[10] || arr[11])) { //�����Ԫ
		fun(0);
		result += "Բ��";
	}

	//�Ƿ�
	if (arr[10]) { //��
		fun(arr[10]);
		result += "��";
		if (!arr[11]) {
			result += "��";
		}
	}
	else {
		if (yuan && arr[11]) {
			fun(0);
		}
	}

	if (arr[11]) { //��
		fun(arr[11]);
		result += "��";
	}

	//������
	cout << "��д�����:" << endl;
    cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}
  