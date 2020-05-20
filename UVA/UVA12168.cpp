#include <bits/stdc++.h>
#define ll long long
#define fastIO cout << fixed << setprecision(12), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

const int N = 1e3 + 9;
string str1[N], str2[N];
int cost[N][N], path[N];
vector<int> adj[N];

int bfs(int src,int dist) {
	memset(path, -1, sizeof path);
	queue<pair<int, int>> q;
	path[src] = -2;
	q.push({src, 1e9});
	while(!q.empty()) {
		int tp = q.front().first;
		int flow = q.front().second;
		q.pop();
		for(auto it: adj[tp]) {
			if(path[it] == -1 && cost[tp][it]) {
				int mxFlow = min(cost[tp][it], flow);
				path[it] = tp;
				if(it == dist)
					return mxFlow;
				q.push({it, mxFlow});
			}
		}
	}
	return 0;
}

int main() {
	fastIO;
#ifdef LOCAL
	freopen("input.in", "rt", stdin);
#endif
	int t;
	cin >> t;
	while(t--) {
		int c, d, v;
		cin >> c >> d >> v;
		for (int i = 0; i <= v; ++i) {
			if(i != v)
				cin >> str1[i] >> str2[i];
			adj[i].clear();
			memset(cost[i], 0, sizeof cost[i]);
		}
		adj[v+1].clear();
		memset(cost[v+1], 0, sizeof cost[v+1]);
		for (int i = 0; i < v; ++i) {
			if(str1[i][0] == 'D') {
				cost[i][v+1] = 1;
				adj[i].push_back(v+1);
				adj[v+1].push_back(i);
				continue;
			}
			adj[v].push_back(i);
			adj[i].push_back(v);
			cost[v][i]++;
			for (int j = 0; j < v; ++j) {
				if(str1[j][0] == 'C') continue;
				if(str1[i] == str2[j] || str2[i] == str1[j]) {
					adj[i].push_back(j);
					adj[j].push_back(i);
					cost[i][j]++;
				}
			}
		}
		int flow = 0, nwFlow;
		while(nwFlow = bfs(v, v+1)) {
			flow += nwFlow;
			int cur = v + 1;
			while(cur != v) {
				int par = path[cur];
				cost[par][cur] -= nwFlow;
				cost[cur][par] += nwFlow;
				cur = par;
			}
		}
		cout << v - flow << '\n';
	}
	return 0;
}

