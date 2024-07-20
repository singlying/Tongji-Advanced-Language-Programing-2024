/*2252748 王昭慧 软件*/
#include<iostream>
#include<math.h>
using namespace std;

void fun2(double delta, double a, double b)
{
	cout << "有两个不等实根：" << endl;
	double x1 = (-b + sqrt(delta)) / (2 * a);
	double x2 = (-b - sqrt(delta)) / (2 * a);
	if (fabs(x1) < 1e-6) { //调零
		x1 = 0.0;
	}
	if (fabs(x2) < 1e-6) { //调零
		x2 = 0.0;
	}

	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}