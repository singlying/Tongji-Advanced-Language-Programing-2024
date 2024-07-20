
#include <iostream>
#include <string>
using namespace std;

#define DESC 0 //降序
#define ASC 1  //升序
#define SUM 10

void input(string name[], string num[], int score[])
{
	for (int i = 0; i < SUM; i++) {
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> num[i] >> name[i] >> score[i];
	}
}

void output(string name[], string num[], int score[])
{
	for (int i = 0; i < SUM; i++)
	{
		if (score[i] <= 60)
		{
			cout << name[i] << " " << num[i] << " " << score[i] << endl;
		}
	}
}

//对成绩进行排序
void bubble_sort_score(string name[], string num[], int score[], int order)
{
	string temp_string;
	int temp_int;

	for (int i = 0; i < SUM - 1; i++) {
		for (int j = 0; j < SUM - i - 1; j++) {
			if (order == ASC ? score[j] > score[j + 1] : score[j] < score[j + 1]) {
				//排序姓名
				temp_string = name[j];
				name[j] = name[j + 1];
				name[j + 1] = temp_string;

				//排序学号
				temp_string = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp_string;

				//排序成绩
				temp_int = score[j];
				score[j] = score[j + 1];
				score[j + 1] = temp_int;

			}
		}
	}
}

int main()
{
	string name[SUM], num[SUM];
	int score[SUM];

	input(name, num, score);

	bubble_sort_score(name, num, score, ASC);
	cout << endl << "不及格名单(成绩升序):" << endl;
	output(name, num, score);

	return 0;
}