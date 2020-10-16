vector < vector<int> > adj, revAdj;
vector<bool> used;
vector<int> topo, component;

void dfsTopo (int v) {
    used[v] = true;
    for(auto it: adj[v])
        if (!used[ adj ])
            dfs1 (adj);
    topo.push_back (v);
}

void dfs2 (int v) {
    used[v] = true;
    component.push_back (v);
    for(auto it: revAdj[v])
        if (!used[ it ])
            dfs2 (it);
}

// reading direct edge from A to B
adj[a].push_back (b);
revAdj[b].push_back (a);


memset(used, 0, sizeof used);
for (int i=0; i<n; ++i)
    if (!used[i])
        dfsTopo (i);
memset(used, 0, sizeof used);

reverse(topo.begin(), topo.end());
vector<vector<int>> comps;
for (int i=0; i<n; ++i) {
    int v = topo[i];
    if (!used[v]) {
        dfs2 (v);
        comps.push_back(component);
        component.clear();
    }
}