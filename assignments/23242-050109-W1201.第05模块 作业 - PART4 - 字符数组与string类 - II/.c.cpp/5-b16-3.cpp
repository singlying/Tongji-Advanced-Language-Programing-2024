
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
		cout << name[i] << " " << num[i] << " " << score[i] << endl;
	}
}

//对学号进行排序
void bubble_sort_num(string name[], string num[], int score[], int order)
{
	string temp_string;
	int temp_int;

	for (int i = 0; i < SUM - 1; i++) {
		for (int j = 0; j < SUM - i - 1; j++) {
			if (order == ASC ? num[j] > num[j + 1] : num[j] < num[j + 1]) {
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

	bubble_sort_num(name, num, score, ASC);
	cout << endl << "全部学生(学号升序):" << endl;
	output(name, num, score);

	return 0;
}