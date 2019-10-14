#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 0) {
		cout << 1;
		return 0;
	}
	if (n % 4 == 0) {
		cout << 6;
		return 0;
	} else if (n % 4 == 1) {
		cout << 8;
		return 0;
	} else if (n % 4 == 2) {
		cout << 4;
		return 0;
	} else {
		cout << 2;
		return 0;
	}
}
