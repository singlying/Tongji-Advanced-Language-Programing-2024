/*2252748 王昭慧 软件*/
#include<iostream>
#include<math.h>
using namespace std;

void fun3(double a, double b)
{
	cout << "有两个相等实根：" << endl;
	double x = -b / (2 * a);
	if (fabs(x) < 1e-6) {
		x = 0.0;
	}

	cout << "x1=x2=" << x << endl;
}