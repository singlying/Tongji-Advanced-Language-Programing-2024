

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define X 10
#define Y 26
#define num 50

//������
int test(const char arr[][Y], int x, int y)
{
	int count = 0;
	if (x - 1 >= 0 && y - 1 >= 0 && arr[x - 1][y - 1] == '*') //����
		count++;
	if (x - 1 >= 0 && arr[x - 1][y] == '*') //��
		count++;
	if (x - 1 >= 0 && y + 1 < Y && arr[x - 1][y + 1] == '*') //����
		count++;
	if (y - 1 >= 0 && arr[x][y - 1] == '*')
		count++;
	if (y + 1 < Y && arr[x][y + 1] == '*')
		count++;
	if (x + 1 < X && y - 1 >= 0 && arr[x + 1][y - 1] == '*')
		count++;
	if (x + 1 < X && arr[x + 1][y] == '*')
		count++;
	if (x + 1 < X && y + 1 < Y && arr[x + 1][y + 1] == '*')
		count++;

	return count;
}

int main()
{
	char arr[X][Y] = {'\0'};

	for (int i = 0; i < X; i++)
		for (int j = 0; j < Y; j++) {
			scanf("%c", &arr[i][j]);
			if (arr[i][j] == ' ' || arr[i][j] == '\n')
			//if (arr[i][j] == ' ')
				j--;
		}

	//����1
	int count = 0;
	for (int i = 0; i < X; i++)
		for (int j = 0; j < Y; j++)
			if (arr[i][j] == '*')
				count++;

	if (count != 50) {
		printf("����1\n");
		return 0;
	}
		
	//����2
	for (int i = 0; i < X; i++)
		for (int j = 0; j < Y; j++)
			if (arr[i][j] != '*' && arr[i][j] != test(arr, i, j) + '0') {
				printf("����2\n");
				return 0;
			}

	printf("��ȷ\n");
	return 0;
}
