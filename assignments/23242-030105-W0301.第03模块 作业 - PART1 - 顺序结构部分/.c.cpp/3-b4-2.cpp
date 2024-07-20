
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	cout << "请输入三角形的两边及其夹角(角度)" << endl;

	int a, b, angle;
	const double Pi = 3.14159;
	cin >> a >> b >> angle;

	cout << "三角形的面积为 : " << setiosflags(ios::fixed) << setprecision(3) << static_cast<float>(0.5 * a * b * sin(Pi * angle / 180)) << endl;

	return 0;
}