/*2252748 ���ѻ� ���*/
#include<iostream>
#include<math.h>
using namespace std;

void fun1()
{
	cout << "����һԪ���η���" << endl;
}

void fun2(double delta, double a, double b)
{
	cout << "����������ʵ����" << endl;
	double x1 = (-b + sqrt(delta)) / (2 * a);
	double x2 = (-b - sqrt(delta)) / (2 * a);
	if (fabs(x1) < 1e-6) { //����
		x1 = 0.0;
	}
	if (fabs(x2) < 1e-6) { //����
		x2 = 0.0;
	}

	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}

void fun3(double a, double b)
{
	cout << "���������ʵ����" << endl;
	double x = -b / (2 * a);
	if (fabs(x) < 1e-6) {
		x = 0.0;
	}

	cout << "x1=x2=" << x << endl;
}

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