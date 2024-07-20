
#include <iostream>
#include <ctime>
using namespace std;

#define SUM 10
static const char other[] = "!@#$%^&*-_=+,.?";
//�������other[]
bool test(char ch)
{
	for (int i = 0; i < sizeof(other) - 1; i++)
		if (ch == other[i])
			return true;
	return false;
}
//��Ҫ��⺯��
bool fun(const char arr[], const int len, const int upper_case, const int lower_case, const int number, const int other_num)
{
	int test_len = 0;
	int test_upper = 0, test_lower = 0, test_number = 0, test_other = 0;

	int j = 0;
	char ch;
	while ((ch = arr[j]) != '\0') {
		if (ch <= 'Z' && ch >= 'A')
			test_upper++;
		else if (ch <= 'z' && ch >= 'a')
			test_lower++;
		else if (ch <= '9' && ch >= '0')
			test_number++;
		else if (test(ch))
			test_other++;
		j++;
	}

	test_len = test_lower + test_upper + test_number + test_other;

	if (test_len != len || test_upper < upper_case || test_lower < lower_case
		|| test_number < number || test_other < other_num)
		return false;
	else
		return true;
}

int main()
{
	cin.ignore(1024, '\n'); //���Ե�һ��

	int len;
	int upper_case, lower_case, number, other_num;
	char arr[10][17];

	cin >> len >> upper_case >> lower_case >> number >> other_num;

	//�������
	if (cin.fail() || len > 16 || len < 12
		|| upper_case < 2 || lower_case < 2
		|| number < 2 || other_num < 2
		|| len < (upper_case + lower_case + number + other_num)) {
		cout << "����" << endl;
		return 0;
	}
	else
		cin.ignore(1024, '\n');

	//����
	//char a = getchar(); //ȥ���������Ļ��з�
	for (int i = 0; i < SUM; i++) {  

		int j = 0;
		char ch;
		while ((ch = getchar()) != '\n' && j < 17) {   //�ж���������룬��ֱ�ӱ����� ���ⱬջ
			arr[i][j] = ch;
			j++;
		}
		if (j == 17) {
			cout << "����" << endl;
			return 0;
		}
		arr[i][j] = '\0';
	}


	bool tag = true;
	for (int i = 0; i < SUM; i++) {
		if (!fun(arr[i], len, upper_case, lower_case, number, other_num))
			tag = false;
	}

	cout << (tag ? "��ȷ" : "����") << endl;

	return 0;
}