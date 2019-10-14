#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((ll) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8;
const double pi = acos(-1);
ll dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
void debug() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "rt", stdin);
//	freopen("output.in", "wt", stdout);
#endif
}

int const N = 1000 + 9, M = 100 + 9, OO = 1e9;

ll a = 2, r = 3;
ll power(ll x, ll y, ll p) {
	ll res = 1;
//    x = x % p;
	while (y > 0) {
		if (y & 1)
			res = ((res % p) * (x % p)) % p;
		y = y >> 1;
		x = ((x % p) * (x % p)) % p;
	}
	return res;
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	ll n, m;
	cin >> n >> m;
	ll ans = (2 * (power(3, n, m) - 1)) / (r - 1);
	ans = ((ans % m) + m) % m;
	cout << ans;
}
