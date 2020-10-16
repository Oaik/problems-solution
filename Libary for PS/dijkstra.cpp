void dij() {
	for (int i = 0; i < N; ++i)
		dist[i] = 1e18;
	priority_queue<pair<ll, int>> pq;
	pq.push({0, 0});
	dist[0] = 0;
	while(!pq.empty()) {
		auto it = pq.top();
		pq.pop();
		ll cost = -it.first;
		int node = it.second;
		if(dist[node] < cost) continue;
		for(auto child: adj[node]) {
			ll nwCost = dist[node] + child.first;
			int nwNode = child.second;
			if(dist[nwNode] > nwCost) {
				dist[nwNode] = nwCost;
				pq.push({-dist[nwNode], nwNode});
			}
		}
	}
}