/*2252748 ���ѻ� ���*/
#include<iostream>
#include<math.h>
using namespace std;

void fun3(double a, double b)
{
	cout << "���������ʵ����" << endl;
	double x = -b / (2 * a);
	if (fabs(x) < 1e-6) {
		x = 0.0;
	}

	cout << "x1=x2=" << x << endl;
}