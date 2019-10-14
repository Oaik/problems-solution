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

int const N = 1e5 + 9, M = 100 + 9, OO = 1e9;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, a, cnt = 0, cntN = 0, total = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if(a > 0)
			++cnt, total += a;
		if(a < 0)
			++cntN;
	}
	int m = n/2 + (n % 2 == 1);
	if(cnt >= m) {
		cout << 1;
	} else if(cntN >= m) {
		cout << -1;
	} else
		cout << 0;
	return 0;
}
