
#include<iostream>
using namespace std;

int main()
{
	cout << "��������������������������20������0������������" << endl;

	int arr[21];
	int num = 0; //λ��ָ��

	while (cin >> arr[num], arr[num] > 0) { //����ԭ����
		num++;
		if (num == 20)
			break;
	}
	cin.ignore(1024, '\n'); //��ջ�����

	if (!num) {
		cout << "����Ч����" << endl;
		return 0;
	}

	cout << "ԭ����Ϊ��" << endl; //���ԭ����
	for (int i = 0; i < num; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "������Ҫ�����������" << endl; //����������
	cin >> arr[num++];

	for (int i = num - 1; i > 1; i--) { //����
		if (arr[i] < arr[i - 1]) {
			int temp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = temp;
		}
		else
			break;
	}
	
	cout << "����������Ϊ��" << endl; //����������
	for (int i = 0; i < num; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}

//1 2 3 4 5 6 7 8 9 10 0
//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22