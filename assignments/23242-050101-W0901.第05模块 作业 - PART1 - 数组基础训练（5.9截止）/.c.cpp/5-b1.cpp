
#include<iostream>
using namespace std;

int main()
{
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;

	int arr[21];
	int num = 0; //位置指针

	while (cin >> arr[num], arr[num] > 0) { //输入原数组
		num++;
		if (num == 20)
			break;
	}
	cin.ignore(1024, '\n'); //清空缓冲区

	if (!num) {
		cout << "无有效输入" << endl;
		return 0;
	}

	cout << "原数组为：" << endl; //输出原数组
	for (int i = 0; i < num; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "请输入要插入的正整数" << endl; //输入正整数
	cin >> arr[num++];

	for (int i = num - 1; i > 1; i--) { //排序
		if (arr[i] < arr[i - 1]) {
			int temp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = temp;
		}
		else
			break;
	}
	
	cout << "插入后的数组为：" << endl; //输出最后数组
	for (int i = 0; i < num; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}

//1 2 3 4 5 6 7 8 9 10 0
//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22