
#include<iostream>
using namespace std;

int main()
{
	int arr[101] = {};

	for (int i = 1; i < 101; i++) {
		for (int j = i; j < 101; j += i) {
			arr[j] = !arr[j];
		}
	}
	

	for (int i = 1, j = 0; i < 101; i++) {
		if (arr[i]) {
			if (!j) {
				cout << i;
				j = 1;
			}
			else
				cout << " " << i;
		}
	}
	cout << endl;

	return 0;
}