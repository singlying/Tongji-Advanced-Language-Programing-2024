
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
	int x;

	//����
	while (1) {
		cout << "������x��ֵ[-10 ~ +65]" << endl;
		cin >> x;

		if (x >= -10 && x <= 65) {
			break;
		}
		else {
			cout << "����Ƿ�������������" << endl;
		}
	}

	//����
	double outcome = 0, division = 1, n = 1;
	while (fabs(division) > 1e-6) {
		outcome += division;
		division *= x / n;
		n++;
	}

	//���
	cout << "e^" << x << "=" << setprecision(10) << outcome << endl;

	return 0;
}