#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 3e5 + 9, OO = 1e9;

struct edge {
  int from, to, w;
  edge(int f, int t, int c) {
    this->from = f;
    this->to = t;
    this->w = c;
  }
  bool operator < (const edge &e) const {
    return w > e.w;
  }
};

vector<vector<edge>> vec;


int main() {
  fastIO;
//  read;
  int t;
  cin >> t;
  while(t--) {
    int n, m, src, goal, u, v, c;
    cin >> n >> m >> src >> goal;
    --src, --goal;
    vec = vector<vector<edge>>(n);
    for (int i = 0; i < m; ++i) {
      cin >> u >> v >> c;
      --u, --v;
      vec[u].push_back(edge(u, v, c));
      vec[v].push_back(edge(v, u, c));
    }
    vector<int> dist(n, OO);
    priority_queue<edge> q;
    dist[src] = 0;
    q.push(edge(-1, src, 0));
    while(!q.empty()) {
      edge tp = q.top();
      q.pop();
      if(tp.w > dist[tp.to])
        continue;
      for(auto child: vec[tp.to]) {
        if(dist[child.to] > dist[tp.to] + child.w) {
          dist[child.to] = dist[tp.to] + child.w;
          q.push(edge(tp.to, child.to, dist[child.to]));
        }
      }
    }
    int val = dist[goal];
    if(val == OO)
      cout << "NONE\n";
    else
      cout << val << '\n';
  }
}

