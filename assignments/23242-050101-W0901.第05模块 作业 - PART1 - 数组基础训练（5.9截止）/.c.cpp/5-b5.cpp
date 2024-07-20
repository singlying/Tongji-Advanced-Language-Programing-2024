
#include<iostream>
using namespace std;

int main()
{
	cout << "请输入成绩（最多1000个），负数结束输入" << endl;

	int arr[1000];
	int score[101] = { 0 };
	int num = 0;

	while (cin >> arr[num], arr[num] > -1) { //输入原数组
		num++;
		if (num == 1000)
			break;
	}
	cin.ignore(1024, '\n'); //清空缓冲区

	if (!num) {
		cout << "无有效输入" << endl;
		return 0;
	}

	cout << "输入的数组为:"; //输出原数组
	for (int i = 0; i < num; i++) {
		if (!(i % 10))
		cout << endl;

		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < num; i++) { //计算人数
		score[arr[i]]++;
	}

	int rank = 1; //排位
	cout << "分数与名次的对应关系为:" << endl; //输出人数
	for (int i = 100; i > -1; i--) {
		for (int j = 0; j < score[i]; j++) {
			cout << i << " " << rank << endl;
		}
		rank += score[i];
	}

	return 0;
}