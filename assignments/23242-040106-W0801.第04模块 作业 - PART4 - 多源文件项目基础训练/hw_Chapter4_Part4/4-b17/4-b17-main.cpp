/*2252748 ���ѻ� ���*/
#include <iostream>
#include <math.h>
using namespace std;

//����
void fun1();
void fun2();
void fun3();
void fun4();

//ȫ�ֱ���
double a, b, c;

int main()
{
	cout << "������һԪ���η��̵�����ϵ��a,b,c:" << endl;
	cin >> a >> b >> c;

	if (fabs(a) < 1e-6) {
		a = 0.0;
	}
	if (fabs(b) < 1e-6) {
		b = 0.0;
	}
	if (fabs(b) < 1e-6) {
		b = 0.0;
	}

	double delta = b * b - 4.0 * a * c;

	if (fabs(a) < 1e-6) { //a = 0
		fun1();
	}
	else if (fabs(delta) < 1e-6) { //�����ʵ��
		fun3();
	}
	else if (delta > 0) { //����ʵ��
		fun2();
	}
	else { //���
		fun4();
	}

	return 0;
}