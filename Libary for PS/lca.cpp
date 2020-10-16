void dfs(int node, int parent int de = 0) {
	inT[node] = ++tmm;
	dist[node] = de;
// Binary lifting
	par[node][0] = parent;
	for (int i = 1; i < 25; ++i) {
		par[node][i] = par[par[node][i - 1]][i - 1];
	}
	for(auto it: adj[node]) {
		if(it == parent) continue;
		dfs(it, node);
	}
	outT[node] = ++tmm;
}


bool isAnc(int node, int req) {
	return inT[node] <= inT[req] && outT[node] >= outT[req];
}

int getLca(int node, int req) {
	if(isAnc(node, req))
		return node;
	if(isAnc(req, node))
		return req;
	for (int i = 24; i >= 0; --i) {
		if(par[node][i] && !isAnc(par[node][i], req))
			node = par[node][i];
	}
	return par[node][0];
}
