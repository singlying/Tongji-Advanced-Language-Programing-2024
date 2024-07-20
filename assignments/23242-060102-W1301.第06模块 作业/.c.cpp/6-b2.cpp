
#include <iostream>
#include <cstring>
using namespace std;

bool is_CircleString(char *str)
{
	int len = strlen(str);
	char* p = str;
	char* q = strlen(str) + str - 2;  //处理掉最后的换行符
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
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(str, 80, stdin);

	if (is_CircleString(str))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return 0;
}