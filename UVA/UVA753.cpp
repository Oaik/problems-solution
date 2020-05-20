#include <bits/stdc++.h>
#define ll long long
#define fastIO cout << fixed << setprecision(12), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

const int N = 3e2 + 9, OO = 1e9;
map<string, vector<string>> adj;
map<string, string> path;
map<string, map<string, int>> cost;

int bfs(string src, string dist) {
	path.clear();
	path[src] = "#";
	queue<pair<string, int>> q;
	q.push({src, OO});
	while(!q.empty()) {
		string tp = q.front().first;
		int flow = q.front().second;
		q.pop();
		for(auto it: adj[tp]) {
			if(path.find(it) == path.end() && cost[tp][it]) {
				int nwFlow = min(flow, cost[tp][it]);
				path[it] = tp;
				if(it == dist)
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
	string str1, str2;
	cin >> t;
	while(t--) {
		adj.clear();
		cost.clear();
		string dist = "*", src = "@";
		int n, total;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> str1;
			adj[dist].push_back(str1);
			adj[str1].push_back(dist);
			cost[str1][dist]++;
		}
		cin >> n;
		total = n;
		for (int i = 0; i < n; ++i) {
			cin >> str1 >> str2;
			adj[src].push_back(str1);
			adj[str1].push_back(src);
			cost[src][str1]++;
			adj[str1].push_back(str2);
			adj[str2].push_back(str1);
			cost[str1][str2]++;
		}
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> str1 >> str2;
			adj[str1].push_back(str2);
			adj[str2].push_back(str1);
			cost[str1][str2] = OO;
		}
		int flow = 0, nwFlow = 0;
		while(nwFlow = bfs(src, dist)) {
			flow += nwFlow;
			string cur = dist;
			while(cur != src) {
				string par = path[cur];
				cost[par][cur] -= nwFlow;
				cost[cur][par] += nwFlow;
				cur = par;
			}
		}
		cout << total - flow << '\n';
		if(t) cout << '\n';
	}
	return 0;
}
