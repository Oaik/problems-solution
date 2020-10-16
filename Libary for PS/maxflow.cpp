int cost[N][N], out[N], par[N];

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

// 			addBiEdge(out[i], i); for node values
// out[i] to in[j] // General formula
// vetrix to edge trick