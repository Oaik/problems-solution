int lowlink[N], dfn[N];
bool instack[N];
int num = 0;
vector<int> g[N];
stack<int> stack_nodes;
int ans = 0;
 
void tarjan(int node) {
    lowlink[node] = dfn[node] = ++num;
    instack[node] = 1;
    stack_nodes.push(node);
    for (int i = 0; i < g[node].size(); i++) {
        int v = g[node][i];
        if (!dfn[v]) {
            tarjan(v);
            lowlink[node] = min(lowlink[node], lowlink[v]);
        } else if (instack[v])
            lowlink[node] = min(lowlink[node], dfn[v]);
    }
    if (lowlink[node] == dfn[node]) {
        int v = -1;
        vector<int> cyc;
        while (v != node) {
            v = stack_nodes.top();
            stack_nodes.pop(), instack[v] = 0;
            cyc.push_back(v);
        }
        if (cyc.size() > 1) ans += cyc.size();
    }
}

for(int i = 0 ; i < idx ; ++i){
    if(!vis[i])
        tarjan(i);
}
