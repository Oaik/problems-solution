#include <iostream>
using namespace std;

int main() {
	int n, k, l, r, total = 0, num = 0;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> l >> r;
		total += (r-l) + 1;
	}
	while((total + num) % k != 0)
		++num;
	cout << num;
}
