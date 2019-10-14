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

int const N = 300009, M = 100 + 9, OO = 1e9;

bool isDot[N];
char str[N];

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, m, cnt = 0, idx = 0;
	cin >> n >> m;
	char l, prv = '?';
	for (int i = 0; i < n; ++i) {
		cin >> l;
		str[i] = l;
		if (l == '.' && l == prv)
			isDot[i] = 1, ++cnt;
		prv = l;
	}
	for (int i = 0; i < m; ++i) {
		cin >> idx >> l;
		--idx;
		if(l == '.' && str[idx] == '.') {
			cout << cnt << endl;
			continue;
		}
		if(l != '.' && str[idx] != '.') {
			cout << cnt << endl;
			continue;
		}
		if (l == '.') {
			if (idx - 1 >= 0 && str[idx - 1] == '.' && !isDot[idx+1]) {
				isDot[idx] = 1;
				++cnt;
			}
			if ( idx + 1 < n && str[idx + 1] == '.' && !isDot[idx+1]) {
				isDot[idx + 1] = 1;
				++cnt;
			}
		} else {
			if (isDot[idx]) {
				isDot[idx] = 0;
				--cnt;
			}
			if (idx + 1 < n && isDot[idx + 1]) {
				isDot[idx + 1] = 0;
				--cnt;
			}
		}
		str[idx] = l;
		cout << cnt << endl;
	}
}
