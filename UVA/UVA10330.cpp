#include <bits/stdc++.h>
#define ll long long
#define fastIO cout << fixed << setprecision(12), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

const int N = 200 + 9, OO = 1e9;
vector<int> adj[N];
int cost[N][N], out[N], par[N];

void addBiEdge(int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int bfs(int s, int t) {
	memset(par, -1, sizeof par);
	par[s] = -2;
	queue<pair<int, int>> qq;
	qq.push({s, OO});
	while(!qq.empty()) {
		int node = qq.front().first, flow = qq.front().second;
		qq.pop();
		for (int i = 0; i < adj[node].size(); ++i) {
			int it = adj[node][i];
			if(par[it] == -1 && cost[node][it]) {
				par[it] = node;
				int nwFlow = min(flow, cost[node][it]);
				if(it == t)
					return nwFlow;
				qq.push({it, nwFlow});
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
	int n, m, u, v, c, a, b;
	while(cin >> n) {
		for (int i = 1; i <= n + n + 2; ++i) {
			adj[i].clear();
			out[i] = i + n;
			memset(cost[i], 0, sizeof cost[i]);
		}
		for (int i = 1; i <= n; ++i) {
			cin >> c;
			addBiEdge(i, out[i]);
			cost[i][out[i]] += c;
		}
		cin >> m;
		for (int i = 0; i < m; ++i) {
			cin >> u >> v >> c;
			addBiEdge(out[u], v);
			cost[out[u]][v] += c;
		}
		cin >> a >> b;
		int start = n + n + 1, end = start + 1;
		for (int i = 0; i < a; ++i) {
			cin >> u;
			addBiEdge(u, start);
			cost[start][u] = OO;
		}
		for (int i = 0; i < b; ++i) {
			cin >> u;
			addBiEdge(out[u], end);
			cost[out[u]][end] = OO;
		}
		int flow = 0, nxtFlow;
		while(nxtFlow = bfs(start, end)) {
			flow += nxtFlow;
			int cur = end;
			while(cur != start) {
				int prv = par[cur];
				cost[prv][cur] -= nxtFlow;
				cost[cur][prv] += nxtFlow;
				cur = prv;
			}
		}
		cout << flow << '\n';
	}
	return 0;
}

