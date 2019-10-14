#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	ll n, x, y;
	ll ans = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		ans = max(ans, x+y);
	}
	cout << ans;
}
