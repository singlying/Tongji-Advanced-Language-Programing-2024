
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	printf("������[0-100��)֮�������:\n");

	double num;
	int an_attempt_to_remove_this_warning = scanf("%lf", &num);

	//��ȡ�������ֺ�С������
	long long integer = (long long)num;
	double decimal = num - integer;

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
	int digit_1 = (int)(round((num - floor(num)) * 100)) / 10 % 10;
	int digit_2 = (int)(round((num - floor(num)) * 100)) % 10;

	//������
	printf("��д�����:\n");

	//��λ
	if (int_10) {  //ʮ��λ
		switch (int_10) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("ʰ");
	}

	if (int_9) { //��λ
		switch (int_9) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
	}

	int yi = 0; //��������������
	if (int_10 || int_9) { //��,ʮ�ڷ���
		printf("��");
		yi = 1;
	}

	//��λ
	if (int_8) { //ǧ��
		switch (int_8) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("Ǫ");
	}
	else { //�ж������
		if (yi && (int_7 || int_6 || int_5)) {
			printf("��");
		}
	}

	if (int_7) { //����
		switch (int_7) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
	}
	else {
		if (int_8 && (int_6 || int_5)) {
			printf("��");
		}
	}

	if (int_6) { //ʮ��
		switch (int_6) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("ʰ");
	}
	else {
		if (int_7 && int_5) {
			printf("��");
		}
	}

	if (int_5) {  //��
		switch (int_5) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
	}

	int wan = 0;
	if (int_8 || int_7 || int_6 || int_5) {
		printf("��");
		wan = 1;
	}
	
	//��λ
	if (int_4) { //ǧ
		switch (int_4) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("Ǫ");
	}
	else { //�ж������
		if ((yi || wan) && (int_3 || int_2 || int_1)) {
			printf("��");
		}
	}

	if (int_3) { //��
		switch (int_3) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
	}
	else {
		if (int_4 && (int_2 || int_1)) {
			printf("��");
		}
	}

	if (int_2) { //ʮ
		switch (int_2) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("ʰ");
	}
	else {
		if (int_3 && int_1) {
			printf("��");
		}
	}

	if (int_1) {  //��
		switch (int_1) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
	}

	//��� Ԫ
	int yuan = 0;
	if (int_1 || int_2 || int_3 || int_4 || int_5 || int_6 || int_7 || int_8 || int_9 || int_10) {
		printf("Բ");
		yuan = 1;
		if (!digit_1 && !digit_2) {
			printf("��");
		}
	}
	else if (!(int_1 || int_2 || int_3 || int_4 || int_5 || int_6 || int_7 || int_8 || int_9 || int_10 || digit_1 || digit_2)) { //�����Ԫ
		printf("��Բ��");
	}

	//�Ƿ�
	if (digit_1) {
		switch (digit_1) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
		if (!digit_2) {
			printf("��");
			//return 0;
		}
	}
	else {
		if (yuan && digit_2) {
			printf("��");
		}
	}

	if (digit_2) { //��
		switch (digit_2) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		printf("��");
	}

	printf("\n");

	return 0;
}