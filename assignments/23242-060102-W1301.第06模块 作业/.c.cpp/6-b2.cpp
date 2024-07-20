
#include <iostream>
#include <cstring>
using namespace std;

bool is_CircleString(char *str)
{
	int len = strlen(str);
	char* p = str;
	char* q = strlen(str) + str - 2;  //��������Ļ��з�
	while (p < q) {
		if (*p != *q) {
			return false;
		}
		p++;
		q--;
	}

	return true;
}

int main()
{
	char str[81];
	cout << "������һ������С��80���ַ��������Ĵ���" << endl;
	fgets(str, 80, stdin);

	if (is_CircleString(str))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return 0;
}