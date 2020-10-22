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

for (int i = 1; i <= n + n + 2; ++i) {
	out[i] = i + n;
}
// make the vertax as an edge
addBiEdge(i, out[i]);
cost[i][out[i]] += c;

// normal edge going from u to v
addBiEdge(out[u], v);
cost[out[u]][v] += c;

addBiEdge(u, start);
cost[start][u] = OO;

addBiEdge(out[u], end);
cost[out[u]][end] = OO;

// in case of biparite Matching problems // 1 --  3
addBiEdge(u, out[v]);                    // 2 /

