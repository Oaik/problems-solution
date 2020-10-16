struct edge
{
    int from, to, cost;
};
int n, m, v;
vector<edge> e;
void solve()
{
    vector<int> d (n, INF);
    d[startNode] = 0;
    while(1) {
        bool still = 0;
        for (int j = 0; j < m; ++j)
            if (d[e[j].from] < INF) {
                if(d[e[j].from] + e[j].cost < d[e[j].to]) {
                    d[e[j].to] = d[e[j].from] + e[j].cost;
//                    d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost); Overflow in negtaive graphs
//                par[e[j].to] = e[j].to;
                    still = 1;
                }
            }
        if(!still)
            break;
    }
//    vector<int> path;
//    for (int cur = t; cur != -1; cur = p[cur])
//        path.push_back (cur);
//    reverse (path.begin(), path.end());
// detect negative cylce loop n times instead of n - 1
// save last vertex X (entered in relaxtion)

    int y = x;
    for (int i=0; i<n; ++i)
        y = p[y];

    vector<int> path;
    for (int cur=y; ; cur=p[cur])
    {
        path.push_back (cur);
        if (cur == y && path.size() > 1)
            break;
    }
    reverse (path.begin(), path.end());

}