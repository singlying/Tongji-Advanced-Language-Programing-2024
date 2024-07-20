
#include <iostream>
#include <ctime>
using namespace std;

#define SUM 10
static const char other[] = "!@#$%^&*-_=+,.?";

//��������
void generator(char arr[], int len, int upper_case, int lower_case, int number, int other_num)
{	
	int left_num = len - upper_case - lower_case - number - other_num;

	int random_num[4] = { upper_case, lower_case, number, other_num };

	//�����µ����ɷ����char�����������
	for (int i = 0; i < left_num; i++) {
		random_num[rand() % 4]++;
	}

	//i˳���һ��λ�ã���4�������������ȡ������������Ͳ����ͼ���
	for (int i = 0; i < len; i++) {
		int choise = rand() % 4;
		if (random_num[choise]) {
			random_num[choise]--;
			switch (choise) {
				case 0: //upper_case
					arr[i] = rand() % 26 + 'A';
					break;
				case 1: //lower_case
					arr[i] = rand() % 26 + 'a';
					break;
				case 2: //number
					arr[i] = rand() % 10 + '0';
					break;
				case 3: //other
					arr[i] = other[rand() % 15];
					break;
			}
		}
		else
			i--;
	}

	//arr[len] = '\0';
}

int main()
{
	srand((unsigned)time(NULL));
	int len;
	int upper_case, lower_case, number, other_num;
	char arr[10][17];

	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;

	cin >> len >> upper_case >> lower_case >> number >> other_num;

	//�ж�������ȷ
	if (cin.fail()) {
		cout << "����Ƿ�" << endl;
		return 0;
	}
	else if (len > 16 || len < 12) {
		cout << "���볤��[" << len << "]����ȷ" << endl;
		return 0;
	}
	else if (upper_case < 2) {
		cout << "��д��ĸ����[" << upper_case << "]����ȷ" << endl;
		return 0;
	}
	else if (lower_case < 2) {
		cout << "Сд��ĸ����[" << lower_case << "]����ȷ" << endl;
		return 0;
	}
	else if (number < 2) {
		cout << "���ָ���[" << number << "]����ȷ" << endl;
		return 0;
	}
	else if (other_num < 2) {
		cout << "�������Ÿ���[" << other_num << "]����ȷ" << endl;
		return 0;
	}
	else if (len < (upper_case + lower_case + number + other_num)) {
		cout << "�����ַ�����֮��[" << upper_case << "+" << lower_case << "+" << number << "+" << other_num << "]���������볤��[" << len << "]" << endl;
		return 0;
	}

	//������������
	cout << len << " " << upper_case << " " << lower_case << " " << number << " " << other_num << endl;

	//����
	for (int i = 0; i < SUM; i++) {
		generator(arr[i], len, upper_case, lower_case, number, other_num);
		//arr[i][len] = '\0';
	}

	//���
	for (int i = 0; i < SUM; i++)
	{
		for (int j = 0; j < len; j++)
			cout << arr[i][j];
		cout << endl;
	}

	return 0;
}