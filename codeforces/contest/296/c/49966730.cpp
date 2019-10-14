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

int const N = 1e5 + 9, M = 500, OO = 5e8 + 9;

ll arr[N], inc[N], comp[N];

vector<pair<pair<int, int>, int>> opt;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, m, k, x, y, d;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> d;
		--x, --y;
		opt.push_back( { { x, y }, d });
	}
	for (int i = 0; i < k; ++i) {
		cin >> x >> y;
		--x, --y;
		++comp[x], --comp[y+1];
	}
	for (int i = 1; i <= m; ++i) {
		comp[i] += comp[i-1];
	}
	int start, end, w;
	ll am = 0;
	for (int j = 0; j < m; ++j) {
		start = opt[j].first.first, end = opt[j].first.second, w = opt[j].second;
		am = comp[j] * w;
		inc[start] += am;
		inc[end+1] -= am;
	}
	for (int i = 1; i <= n; ++i) {
		inc[i] += inc[i-1];
	}
	for (int i = 0; i < n; ++i) {
		cout << arr[i] + inc[i] << " ";
	}
	return 0;
}
