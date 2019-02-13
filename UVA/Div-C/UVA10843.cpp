#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8;
const double pi = acos(-1);

int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
void debug() {
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
}

const ll MOD = 2000000011;
ll k = 0;
// triangle
void solve(ll x) {
	ll res = 1;
	for (int i = 2; i < x; ++i) {
		res = (res * x) % MOD;
	}
	cout << "Case #" << ++k << ": " << res << "\n";
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	ll n, a;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if(a == 2 || a == 1)
			cout << "Case #" << ++k << ": " << 1 << "\n";
		else
			solve(a);
	}
}

