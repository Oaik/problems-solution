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

int const N = 100 + 9, M = 500, OO = 5e8 + 9;

vector<int> par;
int comp;
set<int> elm;

int sz[N];

int find(int x) {
	if(x == par[x]) return x;
	return par[x] = find(par[x]);
}

void join(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return;
	if(sz[x] < sz[y]) swap(x, y);
	par[y] = x;
	sz[x] += sz[y];
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, m, k, x, prev;
	cin >> n >> m;
	par = vector<int>(m), comp = m;
	iota(par.begin(), par.end(), 0);
	fill(sz, sz+N, 1);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> k;
		if(!k) {
			++ans;
			continue;
		}
		for (int j = 0; j < k; ++j) {
			cin >> x;
			--x;
			elm.insert(x);
			if(j) {
				join(x, prev);
			}
			prev = x;
		}
	}
	int comp = 0;
	for(auto it: elm) {
		if(it == par[it])
			++comp;
	}
	cout << ans + max((comp - 1), 0);
	return 0;
}
