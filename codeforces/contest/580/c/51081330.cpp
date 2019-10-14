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

bool isCat[N];
bool visited[N];
int n, m, founds = 0;

vector<vector<int>> vec(N);

void DFS(int u = 0, int cnt = 0) {
	if(visited[u] || cnt + isCat[u] > m)
		return;
	int nums = 0;
	visited[u] = 1;
//	if(isCat[u])
//		++cnt;
//	if(vec[u].size() == 0)
//		++founds;
//	if(cnt > m)
//		return;
	cnt = (isCat[u]) ? cnt + 1: 0;
	for(auto it: vec[u]) {
		if(!visited[it]) {
			DFS(it, cnt);
			++nums;
		}
	}
	if(nums == 0)
		++founds;
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> isCat[i];
	}
	int u, v;
	for (int i = 0; i < n-1; ++i) {
		cin >> u >> v;
		--u, --v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	DFS(0);
	cout << founds;
	return 0;
}
