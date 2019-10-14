#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
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

int const N = 1e6 + 9, M = 100 + 9, OO = 1e9;

int main() {
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	double prv = 0, cur = 0, cmp;
	double a, d, t, v;
	int n;
	cin >> n >> a >> d;
	for (int i = 0; i < n; ++i) {
		cur = 0;
		cin >> t >> v;
		cmp = (v * v) / (2 * a);
		cur = v / a;
		if(cmp >= d) {
			cur = (2 * d) / a;
			cur = sqrt(cur);
		} else {
			cur -= (( (v*v) / (2*a))) /  v;
			cur += (d)/ v;
		}
		cur += t;
		cur = max(cur, prv);
		cout << cur << '\n';
		prv = cur;
	}
	return 0;
}
