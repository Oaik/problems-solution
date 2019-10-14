#include <iostream>
using namespace std;

int main() {
	int n, h, ch, sum;
	cin >> n >> h;
	for (int i = 0; i < n; ++i) {
		cin >> ch;
		if ( ch > h )
			++sum;
		++sum;
	}
	cout << sum;
}