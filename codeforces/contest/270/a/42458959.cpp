#include <iostream>
#include <cmath>

using namespace std;

int main() {
	bool hasDecimal;
	int t, num;
	float x, n;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> num;
		x = num / 180.00;
		n = (2.00) / (1.00 - x);
		hasDecimal = (((int) (round(n * 100))) % 100) != 0;
		if (hasDecimal)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}
