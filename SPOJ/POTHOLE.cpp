#include <bits/stdc++.h>
#define ll long long
#define fastIO cout << fixed << setprecision(12), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

const int N = 209, OO = 1e9;
int cost[N][N], par[N];
vector<int> adj[N];

int bfs(int s, int t) {
	memset(par, -1, sizeof par);
	par[s] = -2;
	queue<pair<int, int>> q;
	q.push({s, OO});
	while(!q.empty()) {
		int node = q.front().first, flow = q.front().second;
		q.pop();
		for(auto it: adj[node]) {
			if(par[it] == -1 && cost[node][it]) {
				par[it] = node;
				int nwFlow = min(flow, cost[node][it]);
				if(it == t)
					return nwFlow;
				q.push({it, nwFlow});
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
		int n, k, u;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			memset(cost[i], 0, sizeof cost[i]);
			adj[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			cin >> k;
			for (int j = 0; j < k; ++j) {
				cin >> u;
				adj[i].push_back(u);
				adj[u].push_back(i);
				if(i == 1 || u == n)
					cost[i][u] = 1;
				else
					cost[i][u] = OO;
			}
		}
		int flow = 0, nwFlow = 0;
		while(nwFlow = bfs(1, n)) {
			flow += nwFlow;
			int cur = n;
			while(cur != 1) {
				int prv = par[cur];
				cost[prv][cur] -= nwFlow;
				cost[cur][prv] += nwFlow;
				cur = prv;
			}
		}
		cout << flow << '\n';
	}
	return 0;
}

