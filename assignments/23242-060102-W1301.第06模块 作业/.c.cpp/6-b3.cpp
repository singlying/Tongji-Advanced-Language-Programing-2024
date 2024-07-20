
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	char binary_num[33];
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin >> binary_num;

	char* p = binary_num;
	unsigned int decimal_num = 0;

	while (*p != '\0') {
		p++;
	}
	p--;  //p指向最后一位
	
	int i = 0;  //代表位数
	while (p >= binary_num) {  //从后向前计算
		decimal_num += (*p - '0') * (unsigned int)pow(2, i);
		i++;
		p--;
	}

	cout << decimal_num << endl;

	return 0;
}
