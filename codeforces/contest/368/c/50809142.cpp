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

int const N = 1e5 + 9, M = 100 + 9, OO = 1e9;


int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	string str, res;
	cin >> str;
	int n, l, r;
	n = str.length();
	int X[n+2], Y[n+2], Z[n+2];
	clr(X, 0);
	clr(Y, 0);
	clr(Z, 0);
	for (int i = 1; i <= n; ++i) {
		if(str[i - 1] == 'x')
			++X[i];
		else if(str[i-1] == 'y')
			++Y[i];
		else
			++Z[i];
	}
	for (int i = 1; i <= n; ++i) {
		X[i] += X[i-1];
		Y[i] += Y[i-1];
		Z[i] += Z[i-1];
	}
	int x, y, z;
	cin >> n;
	while(n--) {
		cin >> l >> r;
		y = (Y[r] - Y[l-1]), x = (X[r] - X[l-1]), z = (Z[r] - Z[l-1]);
//		ans = abs(x-y-z);
		if(r-l>1 && max(y, max(x, z)) - min(y, min(x, z)) > 1) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}
