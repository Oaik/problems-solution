void tarjan(int u){
    dfs_num[u] = dfs_low[u] = tme++;
    vis[u] = true;
    best[u] = u;
    st.push(u);
    inStack[u] = true;
    for(int c : adj[u]){
        if(!vis[c]) {
            tarjan(c);
            dfs_low[u] = min(dfs_low[u] , dfs_low[c]);
        }
        if(inStack[c])dfs_low[u] = min(dfs_low[u] , dfs_num[c]);
    }
    if(dfs_low[u] == dfs_num[u]) {
        while(1){
            int v = st.top();st.pop();
            compRoot[v] = u;
            inStack[v] = false;
            if(u == v)break;
        }
    }
}


for(int i = 0 ; i < idx ; ++i){
    if(!vis[i])
        tarjan(i);
}