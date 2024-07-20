
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define DESC 0 //����
#define ASC 1  //����
#define SUM 10

int input(char name[], char num[])
{
	int score;
	scanf("%s%s%d", num, name, &score);
	return score;
}

void output(char name[][9], char num[][8], int score[])
{
	for (int i = 0; i < SUM; i++)
	{
		printf("%s %s %d\n", name[i], num[i], score[i]);
	}
}

//��ѧ�Ž�������
void bubble_sort_score(char name[][9], char num[][8], int score[], int order)
{
	char temp_char[9];
	int temp_int;

	for (int i = 0; i < SUM - 1; i++) {
		for (int j = 0; j < SUM - i - 1; j++) {
			if (order == ASC ? score[j] > score[j + 1] : score[j] < score[j + 1]) {
				for (int u = 0; u < 9; u++) {  //��������
					temp_char[u] = name[j][u];
					name[j][u] = name[j + 1][u];
					name[j + 1][u] = temp_char[u]; 
				}

				for (int u = 0; u < 8; u++) { //����ѧ��
					temp_char[u] = num[j][u];
					num[j][u] = num[j + 1][u];
					num[j + 1][u] = temp_char[u]; 
				}
				 
				temp_int = score[j];  //����ɼ�
				score[j] = score[j + 1];
				score[j + 1] = temp_int;
			}
		}
	}
}

int main()
{
	char name[SUM][9];
	char num[SUM][8];
	int score[SUM];

	for (int i = 0; i < SUM; i++) {
		printf("�������%d���˵�ѧ�š��������ɼ�\n", i + 1);
		score[i] = input(name[i], num[i]);
	}

	bubble_sort_score(name, num, score, DESC);

	printf("\nȫ��ѧ��(�ɼ�����):\n");
	output(name, num, score);

	return 0;
}