
#include <iostream>
using namespace std;

int main()
{
	char str[3][128];
	int upper = 0, lower = 0, num = 0, space = 0, others = 0;
	
	for (int i = 0; i < 3; i++) {
		cout << "�������" << i + 1 << "��" << endl;
		cin.getline(str[i], 128);

		for (int j = 0; str[i][j] != '\0'; j++) {
			char ch = str[i][j];
			if (ch >= 'A' && ch <= 'Z')
				upper++;
			else if (ch >= 'a' && ch <= 'z')
				lower++;
			else if (ch >= '0' && ch <= '9')
				num++;
			else if (ch == ' ')
				space++;
			else
				others++;
		}
	}

	cout << "��д : " << upper << endl;
	cout << "Сд : " << lower << endl;
	cout << "���� : " << num << endl;
	cout << "�ո� : " << space << endl;
	cout << "���� : " << others << endl;

	return 0;
}