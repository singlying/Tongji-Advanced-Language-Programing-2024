/*2252748 王昭慧 软件*/
#include <iostream>
#include <math.h>
using namespace std;

//声明
void fun1();
void fun2();
void fun3();
void fun4();

//全局变量
double a, b, c;

int main()
{
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
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
	else if (fabs(delta) < 1e-6) { //两相等实根
		fun3();
	}
	else if (delta > 0) { //不等实根
		fun2();
	}
	else { //虚根
		fun4();
	}

	return 0;
}