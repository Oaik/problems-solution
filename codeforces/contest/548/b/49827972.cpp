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

ll const N = 500 + 9, M = 50009, OO = 0x3f3f3f3f;

bool arr[N][N];
int con[N];

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> arr[i][j];
		}
	}
	int a, b, cur = 0, mx = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (arr[i][j]) {
				++cur;
			} else {
				if (cur > mx) {
					con[i] = cur;
					mx = cur;
				}
				cur = 0;
			}
		}
		if (cur > mx) {
			con[i] = cur;
			mx = cur;
		}
		cur = 0, mx = 0;
	}
	while (q--) {
		cin >> a >> b;
		mx = 0, cur = 0;
		if (arr[a][b]) {
			arr[a][b] = 0;
			for (int i = 1; i <= m; ++i) {
				if (arr[a][i])
					++cur;
				else {
					mx = max(cur, mx);
					cur = 0;
				}
			}
			mx = max(cur, mx);
			con[a] = mx;
		} else {
			arr[a][b] = 1;
			for (int i = 1; i <= m; ++i) {
				if (arr[a][i])
					++cur;
				else {
					mx = max(cur, mx);
					cur = 0;
				}
			}
			mx = max(cur, mx);
			con[a] = mx;
		}
		cout << *max_element(con, con + n + 1) << "\n";
	}
	return 0;
}
