
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
	int x;

	//输入
	while (1) {
		cout << "请输入x的值[-10 ~ +65]" << endl;
		cin >> x;

		if (x >= -10 && x <= 65) {
			break;
		}
		else {
			cout << "输入非法，请重新输入" << endl;
		}
	}

	//计算
	double outcome = 0, division = 1, n = 1;
	while (fabs(division) > 1e-6) {
		outcome += division;
		division *= x / n;
		n++;
	}

	//输出
	cout << "e^" << x << "=" << setprecision(10) << outcome << endl;

	return 0;
}