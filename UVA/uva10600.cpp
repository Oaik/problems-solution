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

int const N = 2e5 + 9, M = 100 + 9, OO = 1e9;

vector<pair<int, pair<int, int>>> vec;

bool del[5000];
int par[1001], sz[1001];

int find(int x) {
	if (x == par[x])
		return x;
	return par[x] = find(par[x]);
}

bool join(int x, int y) {
	x = find(x), y = find(y);
	if (x == y)
		return false;
	par[x] = y;
	return true;
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int t, n, m, u, v, c, sz, o = 0;
	ll sum = 0, sum2 = 0, cnt = 0;
	cin >> t;
	while (t--) {
		o = 0;
		vec.clear();
		cin >> n >> m;
		clr(del, 0);
		iota(par, par + n + 1, 0);
		sum = 0, sum2 = 1e9, cnt = 0;
//		clr(sz, 0);
		for (int i = 0; i < m; ++i) {
			cin >> u >> v >> c;
			vec.push_back( { c, { u, v } });
		}
		sort(vec.begin(), vec.end());
		sz = sz(vec);
		for (int i = 0; i < sz; ++i) {
			if (join(vec[i].second.first, vec[i].second.second)) {
				sum += vec[i].first;
				del[i] = 1;
			}
		}
		for (int j = 0; j < sz; ++j) {
			if(!del[j]) continue;
			iota(par, par + n + 1, 0);
			o = 0;
			for (int i = 0; i < sz; ++i) {
				if ( i != j && join(vec[i].second.first, vec[i].second.second)) {
					cnt += vec[i].first;
					++o;
				}
			}
			if(o == n - 1) {
				sum2 = min(sum2, cnt);
			}
			cnt = 0;
		}
		cout << sum << " " << sum2 << endl;
	}
}

