#include <bits/stdc++.h>
#define ll long long
#define fastIO cout << fixed << setprecision(12), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

const int N = 50, OO = 1e9;
vector<int> adj[N];
int cost[N][N], par[N], total, cnt[N];
char ans[N];

void addBiEdge(int u, int v, int c) {
	adj[u].push_back(v);
	adj[v].push_back(u);
	cost[u][v] = c;
}

void clr() {
	total = 0;
	for (int i = 0; i < N; ++i) {
		cnt[i] = 0;
		ans[i] = '_';
		adj[i].clear();
		for (int j = 0; j < N; ++j)
			cost[i][j] = 0;
	}
}

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

void solve() {
	int start = 37, end = 38;
	for (int i = 10; i <= 36; ++i)
		addBiEdge(start, i, cnt[i]);
	for (int i = 0; i < 10; ++i)
		addBiEdge(i, end, 1);
	int flow = 0, nwFlow;
	while(nwFlow = bfs(start, end)) {
		flow += nwFlow;
		int cur = end;
		vector<int> path;
		while(cur != start) {
			int prv = par[cur];
			path.push_back(prv);
			cost[prv][cur] -= nwFlow;
			cost[cur][prv] += nwFlow;
			cur = prv;
		}
		path.pop_back();
		reverse(path.begin(), path.end());

		cur = path[0];
		for (int i = 1; i < (int)path.size(); i += 2) {
			ans[path[i]] = (char)((cur - 10) + 'A');
			if(i + 1 < (int)path.size())
				cur = path[i + 1];
		}
	}
	if(total != flow) {
		cout << '!' << '\n';
		return;
	}
	for (int i = 0; i < 10; ++i)
		cout << ans[i];
	cout << '\n';
}

int main() {
	fastIO;
#ifdef LOCAL
	freopen("input.in", "rt", stdin);
#endif
	string str;
	clr();
	while(getline(cin, str)) {
		if(str.empty()) {
			solve();
			clr();
			continue;
		}
		int node = str[0] - 'A' + 10, n = str[1] - '0';
		cnt[node] = n;
		total += n;
		for (int i = 0;; ++i) {
			if(str[i + 3] == ';') break;
			addBiEdge(node, str[i + 3] - '0', 1);
		}
	}
	solve();
	return 0;
}

