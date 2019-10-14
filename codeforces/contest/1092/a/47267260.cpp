#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t, n, k, idx = 0;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		idx = 0;
		cin >> n >> k;
		for (int i = 0; i < n; ++i) {
			cout << (char)('a' + idx);
			++idx;
			if(idx >= k)
				idx = 0;
		}
		cout << "\n";
	}
}
