#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<pair<ll, ll>> vl;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(0);
	ll l, r, n;
	cin >> l >> r;
	n = (r-l+1)/2;
	for (ll i = l; i <= r && vl.size() < n; i+=2) {
		vl.push_back({i, i+1});
	}

	if(vl.size() == n) {
		cout << "YES\n";
		for(auto l: vl) {
			cout << l.first << " " << l.second << "\n";
		}
	} else {
		cout << "NO";
	}
}
