#include <iostream>
#include <cmath>

using namespace std;

int main() {
	bool hasDecimal;
	int t, num;
	float x, f;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> num;
		f = 180 / num;
		x = (2 * f) / (f - 1);
		hasDecimal = (((int) (round(x * 100))) % 100) != 0;
		if (hasDecimal)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}
