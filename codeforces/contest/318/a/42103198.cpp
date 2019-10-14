#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n = 0, k = 0, odds = 0;
	cin >> n >> k;
	if ((n % 2) == 0)
		odds = n / 2;
	else
		odds = (n + 1) / 2;
	int cmp = odds - k;
	if (cmp >= 0) {
		cout << 2 * (k - 1) + 1;
	} else
		cout << 2 * (k - odds);
	return 0;
}
