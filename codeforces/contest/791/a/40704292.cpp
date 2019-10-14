#include <iostream>
using namespace std;

int main() {
	int a, b, sumYears = 0;
	cin >> a >> b;
	if (a == b) {
		cout << 1;
		return 0;
	}
	for (int i = 0; a <= b; ++i) {
		a *= 3;
		b *= 2;
		++sumYears;
	}
	cout << sumYears;
	return 0;
}