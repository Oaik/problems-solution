#include <bits/stdc++.h>

using namespace std;

int r[10009];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> r[i];
	int d = 0, mx = r[0], cnt = 0;
	while(cnt < n) {
		while(cnt < mx) {
			mx = max(mx, r[cnt]);
			++cnt;
		}
		++d;
		mx = r[cnt];
	}
	cout << d;
}
