
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	cout << "�����������ε����߼���н�(�Ƕ�)" << endl;

	int a, b, angle;
	const double Pi = 3.14159;
	cin >> a >> b >> angle;

	cout << "�����ε����Ϊ : " << setiosflags(ios::fixed) << setprecision(3) << static_cast<float>(0.5 * a * b * sin(Pi * angle / 180)) << endl;

	return 0;
}