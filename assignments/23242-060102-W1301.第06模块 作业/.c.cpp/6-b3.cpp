
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	char binary_num[33];
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
	cin >> binary_num;

	char* p = binary_num;
	unsigned int decimal_num = 0;

	while (*p != '\0') {
		p++;
	}
	p--;  //pָ�����һλ
	
	int i = 0;  //����λ��
	while (p >= binary_num) {  //�Ӻ���ǰ����
		decimal_num += (*p - '0') * (unsigned int)pow(2, i);
		i++;
		p--;
	}

	cout << decimal_num << endl;

	return 0;
}
