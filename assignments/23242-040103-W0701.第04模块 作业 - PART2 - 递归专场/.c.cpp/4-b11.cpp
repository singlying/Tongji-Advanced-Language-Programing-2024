
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������ݹ麯�����������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
				 2����print_tower֮������������в������徲̬�ֲ�����
   ----------------------------------------------------------------------------------- */

void circle_2(char ch, const char end, int order) //order : 1 ���� 0����
{
	if (ch == end && order) {
		cout << ch;
		return;
	}
	else if (ch == 'A' && 'A' != end) {
		cout << 'A';
		circle_2(ch + 1, end, 1);
		return;
	}
	else if (end == 'A') {
		cout << 'A';
		return;
	}
	else if (!order) {
		cout << ch;
		circle_2(ch - 1, end, 0);
		return;
	}
	else {
		cout << ch;
		circle_2(ch + 1, end, 1);
	}
}

void circle_1(int num, const int sum, int order) //order : 1 ���� 0����
{
	if (!num) {
		return;
	}
	else if (order){ //����
		circle_1(num - 1, sum, 1);

		cout << setw(sum - num) << setfill(' ') << "";
		circle_2(char('A' + num - 1), char('A' + num - 1), 0);
		cout << endl;
	}
	else { //����
		cout << setw(sum - num) << setfill(' ') << "";
		circle_2(char('A' + num - 1), char('A' + num - 1), 0);
		cout << endl;

		circle_1(num - 1, sum, 0);
	}
}


   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡ��ĸ��
	 ���������
	 �� �� ֵ��
	 ˵    �����βΰ�������
			   ��ʾ����һ������order��ָ������/����
   ***************************************************************************/
   /* �����趨�����һ����̬�ֲ�������Ҳ���Բ����壩 */
	   /* ����ʵ�֣������в������κ���ʽ��ѭ����������������������� */
void print_tower(char ch, int order, int adjustment) //order: 1 ���� 0 ���� adjustment �Ƿ��������: 1 �������� 0 ������
{
	if (order && !adjustment) { //���� ����������
		circle_1(ch - 'A' + 1, ch - 'A' + 1, 1);
	}
	else if (!order && !adjustment) { //���� ����������
		circle_1(ch - 'A' + 1, ch - 'A' + 1, 0);
	}
	else if (order && adjustment) { //���� ��������
		circle_1(ch - 'A' + 1, ch - 'A' + 2, 1);
	}
	else { //���� ��������
		circle_1(ch - 'A' + 1, ch - 'A' + 2, 0);
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч��Ϊ����ѭ�����֣��������������) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(�м�ΪA) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "" << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "" << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch, 1, 0); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ��������ĸ��(�м�ΪA) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "" << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "" << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch, 0, 0); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ����������Ư�������Σ��м�ΪA�� */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "" << endl;/* ����ĸ����������= */
	cout << "����(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "" << endl;/* ����ĸ����������= */
	print_tower(end_ch, 1, 0);  //��ӡ A~�����ַ��������� 
	print_tower(end_ch - 1, 0, 1);   //��ӡ A~�����ַ�-1�ĵ����� 
	cout << endl;

	return 0;
}
