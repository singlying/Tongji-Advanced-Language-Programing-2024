/*2252748 王昭慧 软件*/
#include<iostream>
#include<math.h>
using namespace std;

void fun4(double delta, double a, double b)
{
	cout << "有两个虚根：" << endl;
	double real_part = -b / (2.0 * a);
	double imaginary_part = sqrt(-delta) / (2.0 * fabs(a)); //把虚部调为正数

	if (fabs(real_part) <= 1e-6) { //实部为0，则不需要输出加号
		if (fabs(imaginary_part - 1) < 1e-6) { //虚部为1 不需要输出1
			cout << "x1=i" << endl;
			cout << "x2=-i" << endl;
		}
		else { //虚部不为1，需要输出
			cout << "x1=" << imaginary_part << "i" << endl;
			cout << "x2=" << -imaginary_part << "i" << endl;
		}
	}
	else { //实部不为0
		if (fabs(imaginary_part - 1) < 1e-6) { //虚部为1
			cout << "x1=" << real_part << "+i" << endl;
			cout << "x2=" << real_part << "-i" << endl;
		}
		else { //虚部不为1
			cout << "x1=" << real_part << "+" << imaginary_part << "i" << endl;
			cout << "x2=" << real_part << -imaginary_part << "i" << endl;
		}
	}
}
