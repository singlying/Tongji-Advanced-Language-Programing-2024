
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//�ɰ���������Ҫ��ͷ�ļ�

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
int fun(int num, int i)  //�����д����
{
	result[i++] = chnstr[num * 2];
	result[i++] = chnstr[num * 2 + 1];
	return i;
}


int main()
{
	printf("������[0-100��)֮�������:\n");

	double num;
	scanf("%lf", &num);
	int arr[12];

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

	int i = 0;

	if (arr[0]) { //ʮ��λ
		i = fun(arr[0], i);
		sprintf(result + i, "ʰ");
		i += 2;  //GB���ֱ���ռ2���ַ�
	}

	if (arr[1]) { //��λ
		i = fun(arr[1], i);
	}

	int yi = 0; //��������������
	if (arr[0] || arr[1]) { //��,ʮ�ڷ���
		sprintf(result + i, "��");
		yi = 1;
		i += 2;
	}

	//��λ
	if (arr[2]) {  //ǧ��
		i = fun(arr[2], i);
		sprintf(result + i, "Ǫ");
		i += 2;
	}
	else { //�ж������
		if (yi && (arr[3] || arr[4] || arr[5])) {
			i = fun(0, i);
		}
	}

	if (arr[3]) { //����
		i = fun(arr[3], i);
		sprintf(result + i, "��");
		i += 2;
	}
	else {
		if (arr[2] && (arr[4] || arr[5])) {
			i = fun(0, i);
		}
	}

	if (arr[4]) { //ʮ��
		i = fun(arr[4], i);
		sprintf(result + i, "ʰ");
		i += 2;
	}
	else {
		if (arr[3] && arr[5]) {
			i = fun(0, i);
		}
	}

	if (arr[5]) {  //��
		i = fun(arr[5], i);
	}

	int wan = 0;
	if (arr[2] || arr[3] || arr[4] || arr[5]) {
		sprintf(result + i, "��");
		i += 2;
		wan = 1;
	}

	//��λ
	if (arr[6]) { //ǧ
		i = fun(arr[6], i);
		sprintf(result + i, "Ǫ");
		i += 2;
	}
	else { //�ж������
		if ((yi || wan) && (arr[7] || arr[8] || arr[9])) {
			i = fun(0, i);
		}
	}

	if (arr[7]) { //��
		i = fun(arr[7], i);
		sprintf(result + i, "��");
		i += 2;
	}
	else {
		if (arr[6] && (arr[8] || arr[9])) {
			i = fun(0, i);
		}
	}

	if (arr[8]) { //ʮ
		i = fun(arr[8], i);
		sprintf(result + i, "ʰ");
		i += 2;
	}
	else {
		if (arr[7] && arr[9]) {
			i = fun(0, i);
		}
	}

	if (arr[9]) {  //��
		i = fun(arr[9], i);
	}

	//��� Ԫ
	int yuan = 0;
	if (arr[9] || arr[8] || arr[7] || arr[6] || wan || yi) {
		sprintf(result + i, "Բ");
		i += 2;
		yuan = 1;
		if (!arr[10] && !arr[11]) {
			sprintf(result + i, "��");
			i += 2;
		}
	}
	else if (!(arr[9] || arr[8] || arr[7] || arr[6] || wan || yi || arr[10] || arr[11])) { //�����Ԫ
		i = fun(0, i);
		sprintf(result + i, "Բ��");
		i += 2;
	}

	//�Ƿ�
	if (arr[10]) { //��
		i = fun(arr[10], i);
		sprintf(result + i, "��");
		i += 2;
		if (!arr[11]) {
			sprintf(result + i, "��");
			i += 2;
		}
	}
	else {
		if (yuan && arr[11]) {
			i = fun(0, i);
		}
	}

	if (arr[11]) { //��
		i = fun(arr[11], i);
		sprintf(result + i, "��");
		i += 2;
	}

	//������
	printf("��д�����:\n");
	printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
	return 0;
}
