
#include<iostream>
using namespace std;

int main()
{
	cout << "������ɼ������1000������������������" << endl;

	int arr[1000];
	int score[101] = { 0 };
	int num = 0;

	while (cin >> arr[num], arr[num] > -1) { //����ԭ����
		num++;
		if (num == 1000)
			break;
	}
	cin.ignore(1024, '\n'); //��ջ�����

	if (!num) {
		cout << "����Ч����" << endl;
		return 0;
	}

	cout << "���������Ϊ:"; //���ԭ����
	for (int i = 0; i < num; i++) {
		if (!(i % 10))
		cout << endl;

		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < num; i++) { //��������
		score[arr[i]]++;
	}

	int rank = 1; //��λ
	cout << "���������εĶ�Ӧ��ϵΪ:" << endl; //�������
	for (int i = 100; i > -1; i--) {
		for (int j = 0; j < score[i]; j++) {
			cout << i << " " << rank << endl;
		}
		rank += score[i];
	}

	return 0;
}