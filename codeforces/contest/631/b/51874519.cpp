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

int const N = 5e3 + 9, M = 1e6 + 9, OO = 1e9;

int arr[N][N];


vector<pair<pair<int, int>, int>> st;

bool col[N], row[N];

int main() {
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, m, k, a, b, c;
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) {
		cin >> a >> b >> c;
		--b;
		st.push_back({{a, b}, c});
//		if(a == 1) {
//			for (int i = 0; i < m; ++i) {
//				arr[b][i] = c;
//			}
//		} else {
//			for (int i = 0; i < n; ++i) {
//				arr[i][b] = c;
//			}
//		}
	}
	for (int i = k-1; i >= 0; --i) {
		if(st[i].first.first == 1) {
			if(row[st[i].first.second])
				continue;
			for (int j = 0; j < m; ++j) {
				if(arr[st[i].first.second][j])
					continue;
				arr[st[i].first.second][j] = st[i].second;
			}
			row[st[i].first.second] = 1;
		} else {
			if(col[st[i].first.second])
				continue;
			for (int j = 0; j < n; ++j) {
				if(arr[j][st[i].first.second])
					continue;
				arr[j][st[i].first.second] = st[i].second;
			}
			col[st[i].first.second] = 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}
