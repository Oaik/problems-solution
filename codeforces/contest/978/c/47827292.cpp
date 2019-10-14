#include <bits/stdc++.h>

using namespace std;
#define ll long long

const double EPS = 1e-8;

int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}

ll rooms[200001];

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.in", "w", stdout);
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	ll n, m;
	ll a, b;
	cin >> n >> m;
	rooms[0] = 0;
	for (ll i = 1; i <= n; ++i) {
		cin >> a;
		rooms[i] = a + rooms[i-1];
	}
	ll j = 0;
	for (ll i = 0; i < m; ++i) {
		cin >> b;
		while(1) {
			if(rooms[j] >= b)
				break;
			++j;
		}
		cout << j << " " << b - rooms[j-1] << "\n";
	}
	return 0;
}
