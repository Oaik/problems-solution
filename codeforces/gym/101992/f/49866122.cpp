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
	//freopen("output.in", "wt", stdout);
#endif
}

ll const N = 1e5 + 9, M = 500, OO = 1e12 + 9;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
// 	debug();
	freopen("mosalah.in", "rt", stdin);
	int n, m, x, y, t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> x >> y;
		if (y == 0) {
			if ( (m/x) >= n) {
				cout << "0\n";
				continue;
			}
			cout << "-1\n";
			continue;
		}
		int totalLastG = n * (x + y);
		int rem = totalLastG - m;

		cout << (rem >= 0 ? rem : 0) << "\n";
	}
	return 0;
}
