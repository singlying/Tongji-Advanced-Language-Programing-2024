
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "请输入一个[1..30000]间的整数:" << endl;

	unsigned int a;

	cin >> a;
	cout << "万位 : " << a / 10000 << endl;
	
	a = a % 10000;
	cout << "千位 : " << a / 1000 << endl;

	a = a % 1000;
	cout << "百位 : " << a / 100 << endl;

	a = a % 100;
	cout << "十位 : " << a / 10 << endl;

	a = a % 10;
	cout << "个位 : " << a << endl;


	return 0;
}