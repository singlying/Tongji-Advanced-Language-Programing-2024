
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "请输入半径和高度" << endl;

	float r, h;
	cin >> r >> h;

	const float Pi = 3.14159f;
	cout << "圆周长     : ";
	cout << setiosflags(ios::fixed) << setprecision(2) << 2 * Pi * r << endl;
	cout << "圆面积     : ";
	cout << setiosflags(ios::fixed) << setprecision(2) << Pi * r * r << endl;
	cout << "圆球表面积 : ";
	cout << setiosflags(ios::fixed) << setprecision(2) << Pi * r * r * 4 << endl;
	cout << "圆球体积   : ";
	cout << setiosflags(ios::fixed) << setprecision(2) << Pi * r * r * r * 4 / 3 << endl;
	cout << "圆柱体积   : ";
	cout << fixed << setprecision(2) << h * Pi * r * r << endl;

	return 0;
}