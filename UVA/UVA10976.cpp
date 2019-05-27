#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 2e9 + 9;

struct edge {
  int from, to, w;
  edge (int x, int y, int c) :
    from(x), to(y), w(c) {}
  bool operator <(const edge &e) const {
    return e.w < w;
  }
};

int main() {
  debug();
  int t;
  cin >> t;
  for(int k = 1; k <= t; ++k) {
    int n, m, src, dist, u, v, c;
    cin >> n >> m >> src >> dist;
    vector<pair<int, int>> adjList[n];
    for (int i = 0; i < m; ++i) {
      cin >> u >> v >> c;
      adjList[u].push_back({v, c});
      adjList[v].push_back({u, c});
    }
    // dijkstra
    vector<int> dis(n, OO);
    priority_queue<edge> q;
    q.push(edge(-1, src, 0));
    dis[src] = 0;
    edge e(0, 0, 0);
    while(!q.empty()) {
      e = q.top();
      q.pop();
      if(e.w > dis[e.to])
        continue;
      for (int i = 0; i < (int)adjList[e.to].size(); ++i) {
        int child = adjList[e.to][i].first, cost = adjList[e.to][i].second;
        if(dis[child] > dis[e.to] + cost) {
          dis[child] = dis[e.to] + cost;
          q.push(edge(e.to, child, dis[child]));
        }
      }
    }
    cout << "Case #" << k << ':' << ' ';
    if(dis[dist] == OO)
      cout << "unreachable" << endl;
    else
      cout << dis[dist] << endl;
  }

}

