#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "r", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e4 + 9, M = 2e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

struct edge {
  int from, to;ll dist;
  edge(int f, int t, ll d) {
    from = f, to = t, dist = d;
  }
  bool operator <(const edge &e) const {
    return dist > e.dist;
  }
};

vector<pair<int, ll>> vec[N], vecRev[N];
vector<edge> edgeList;
int n, m, s, e, p, u, v, c;
ll dist1[N], dist2[N];


int main() {
//  read("input.in");
//  write("output.in");
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> s >> e >> p;
    edgeList.clear();
    for (int i = 1; i <= n; ++i)
      vec[i].clear(),vecRev[i].clear(), dist1[i] = OO, dist2[i] = OO;

    for (int i = 0; i < m; ++i) {
      cin >> u >> v >> c;
      edgeList.push_back(edge(u, v, c));
      vec[u].push_back( { v, c });
      vecRev[v].push_back( { u, c });
    }

    priority_queue<edge> pq;
    dist1[s] = 0;
    pq.push(edge(-1, s, 0));

    while(!pq.empty()) {
      edge e = pq.top();
      pq.pop();
      if(e.dist > dist1[e.to])
        continue;
      for(auto it: vec[e.to]) {
        if(dist1[it.first] > it.second + e.dist) {
          dist1[it.first] = it.second + e.dist;
          pq.push(edge(e.to, it.first, dist1[it.first]));
        }
      }
    }

    pq.push(edge(-1, e, 0));
    dist2[e] = 0;

    while(!pq.empty()) {
      edge e = pq.top();
      pq.pop();
      if(e.dist > dist2[e.to])
        continue;
      for(auto it: vecRev[e.to]) {
        if(dist2[it.first] > it.second + e.dist) {
          dist2[it.first] = it.second + e.dist;
          pq.push(edge(e.to, it.first, dist2[it.first]));
        }
      }
    }

    ll mx = -1;
    for (int i = 0; i < m; ++i) {
//      ll distFrom = dist1[edgeList[i].from], distTo = dist2[edgeList[i].to];
      if(dist1[edgeList[i].from] + dist2[edgeList[i].to] + edgeList[i].dist <= p) {
        mx = max(mx, edgeList[i].dist);
      }
    }

    cout << mx << '\n';
  }
  return 0;
}

