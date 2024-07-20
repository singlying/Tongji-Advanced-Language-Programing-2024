
#include <iostream>
#include <ctime>
using namespace std;

#define X 10
#define Y 26
#define num 50

//检测个数
int test(const char arr[][Y], int x, int y)
{
	int count = 0;
	if (x - 1 >= 0 && y - 1 >= 0 && arr[x - 1][y - 1] == '*') //左上
		count++;
	if (x - 1 >= 0 && arr[x - 1][y] == '*') //上
		count++;
	if (x - 1 >= 0 && y + 1 < Y && arr[x - 1][y + 1] == '*') //右上
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
	srand(time(0));

	char arr[X][Y] = { };

	for (int i = 0; i < num; i++) {
		int temp_x = rand() % X;
		int temp_y = rand() % Y;

		if (arr[temp_x][temp_y] == '*')
			i--;
		else
			arr[temp_x][temp_y] = '*';
	}

	for (int i = 0; i < X; i++)
		for (int j = 0; j < Y; j++)
			if (!arr[i][j])
				arr[i][j] = test(arr, i, j) + '0';


	for (int i = 0; i < X; i++) //输出
	{
		for (int j = 0; j < Y; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}

	return 0;
}