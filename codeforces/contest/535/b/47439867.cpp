#include <bits/stdc++.h>

using namespace std;
#define ll long long

map<int, int> mp1;
map<int, int> mp2;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, c = 0, idx = 0;
	ll ans = 0;
	cin >> n;
	while(n > 0) {
		c = n % 10;
		n/=10;
		ans += (c == 4) ? pow(2,idx) : 2*pow(2,idx);
		++idx;
	}
	cout << ans;
    return 0;
}
