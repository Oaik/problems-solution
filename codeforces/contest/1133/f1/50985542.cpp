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

int par[N], arr[N], nd[N];

int find(int x) {
	if (x == par[x])
		return x;
	return par[x] = find(par[x]);
}

bool join(int x, int y) {
	x = find(x), y = find(y);
	if (x == y)
		return 0;
	par[x] = y;
	return 1;
}

vector<pair<int, int>> vec;
vector<vector<int>> res(N);

int main() {
	cout << fixed << setprecision(2);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, m, u, v;
	cin >> n >> m;
	iota(par, par + n + 1, 0);
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		++arr[u], ++arr[v];
		res[u].push_back(v);
		res[v].push_back(u);
		vec.push_back( { u, v });
	}
	int mx = 0, node = -1;
	for (int i = 0; i <= n; ++i) {
		if(arr[i] >= mx ) {
			mx = arr[i];
			node = i;
		}
	}
	for(auto it: res[node]) {
		join(node, it);
		cout << node << " " << it << "\n";
	}
	for(auto it: vec) {
		if(join(it.first, it.second)) {
			cout << it.first << " "<< it.second << "\n";
		}
	}
}
