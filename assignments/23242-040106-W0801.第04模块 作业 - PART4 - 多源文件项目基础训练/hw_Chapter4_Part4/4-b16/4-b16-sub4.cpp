/*2252748 ���ѻ� ���*/
#include<iostream>
#include<math.h>
using namespace std;

void fun4(double delta, double a, double b)
{
	cout << "�����������" << endl;
	double real_part = -b / (2.0 * a);
	double imaginary_part = sqrt(-delta) / (2.0 * fabs(a)); //���鲿��Ϊ����

	if (fabs(real_part) <= 1e-6) { //ʵ��Ϊ0������Ҫ����Ӻ�
		if (fabs(imaginary_part - 1) < 1e-6) { //�鲿Ϊ1 ����Ҫ���1
			cout << "x1=i" << endl;
			cout << "x2=-i" << endl;
		}
		else { //�鲿��Ϊ1����Ҫ���
			cout << "x1=" << imaginary_part << "i" << endl;
			cout << "x2=" << -imaginary_part << "i" << endl;
		}
	}
	else { //ʵ����Ϊ0
		if (fabs(imaginary_part - 1) < 1e-6) { //�鲿Ϊ1
			cout << "x1=" << real_part << "+i" << endl;
			cout << "x2=" << real_part << "-i" << endl;
		}
		else { //�鲿��Ϊ1
			cout << "x1=" << real_part << "+" << imaginary_part << "i" << endl;
			cout << "x2=" << real_part << -imaginary_part << "i" << endl;
		}
	}
}
