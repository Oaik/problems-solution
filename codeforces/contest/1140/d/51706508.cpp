#include <bits/stdc++.h>

using namespace std;


int main() {
	int n;
	cin >> n;
	long long total = 0;
	for (long long i = 3; i <= n; ++i) {
		total += (i * (i-1));
	}
	cout << total;
}
