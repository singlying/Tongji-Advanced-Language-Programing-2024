
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "������һ��[1..30000]�������:" << endl;

	unsigned int a;

	cin >> a;
	cout << "��λ : " << a / 10000 << endl;
	
	a = a % 10000;
	cout << "ǧλ : " << a / 1000 << endl;

	a = a % 1000;
	cout << "��λ : " << a / 100 << endl;

	a = a % 100;
	cout << "ʮλ : " << a / 10 << endl;

	a = a % 10;
	cout << "��λ : " << a << endl;


	return 0;
}