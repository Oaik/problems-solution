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

int const N = 101, M = 100 + 9, OO = 1e9;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, x, y, a, b;
	ll cnt = 0;
	cin >> n >> x >> y;
	cnt = min(x, y) + 1;
	for (int i = 1; i < n; ++i) {
		cin >> a >> b;
		if(a == x && b == y)
			continue;

		if(x == y) {
			cnt += min(a, b) - x;
		} else if(x > y) { // max is x
			if(a == b) {
				cnt += a - x + 1;
			} else if(a > b) {
				if(b >= x)
					cnt += b - x + 1;
			} else {
				if(b >= x)
					cnt += 1 + a - x;
			}
		} else { // max is y
			if(a == b)
				cnt += b - y + 1;
			else if(b > a) {
				if(a >= y)
					cnt += a - y + 1;
			} else {
				if(a >= y)
					cnt += 1 + b - y;
			}
		}

		x = a, y = b;
	}
	cout << cnt;
	return 0;
}
