
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define DESC 0 //降序
#define ASC 1  //升序
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

//对学号进行排序
void bubble_sort_score(char name[][9], char num[][8], int score[], int order)
{
	char temp_char[9];
	int temp_int;

	for (int i = 0; i < SUM - 1; i++) {
		for (int j = 0; j < SUM - i - 1; j++) {
			if (order == ASC ? score[j] > score[j + 1] : score[j] < score[j + 1]) {
				for (int u = 0; u < 9; u++) {  //排序姓名
					temp_char[u] = name[j][u];
					name[j][u] = name[j + 1][u];
					name[j + 1][u] = temp_char[u]; 
				}

				for (int u = 0; u < 8; u++) { //排序学号
					temp_char[u] = num[j][u];
					num[j][u] = num[j + 1][u];
					num[j + 1][u] = temp_char[u]; 
				}
				 
				temp_int = score[j];  //排序成绩
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
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		score[i] = input(name[i], num[i]);
	}

	bubble_sort_score(name, num, score, DESC);

	printf("\n全部学生(成绩降序):\n");
	output(name, num, score);

	return 0;
}