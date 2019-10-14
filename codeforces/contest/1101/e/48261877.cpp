#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((int) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8;

int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
void debug() {
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
}

vector<pair<ll, ll>> vec;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	ll n, x, y, mx1 = 0, mx2 = 0;
	char q;
	cin >> n;
	bool yes = true;
	for (ll i = 0; i < n; ++i) {
		cin >> q >> x >> y;
		yes = true;
		if(q == '+') {
			mx1 = max(mx1, min(x, y));
			mx2 = max(mx2, max(x, y));
		} else {
			if(mx1 <= min(x, y) && mx2 <= max(y, x))
				yes = true;
			else
				yes = false;
			if(yes) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}

}
