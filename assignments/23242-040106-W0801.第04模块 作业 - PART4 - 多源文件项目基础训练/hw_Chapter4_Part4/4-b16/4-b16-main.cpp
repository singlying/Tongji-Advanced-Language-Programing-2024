/*2252748 王昭慧 软件*/
#include<iostream>
#include<math.h>
#include "4-b16.h"
using namespace std;

int main()
{
	double a, b, c;

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
		fun3(a, b);
	}
	else if (delta > 0) { //不等实根
		fun2(delta, a, b);
	}
	else { //虚根
		fun4(delta, a, b);
	}

	return 0;
}