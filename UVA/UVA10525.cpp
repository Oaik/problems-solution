#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout << fixed << setprecision(3)
double const EPS = 1e-8, PI = acos(-1);
const ll N = 1e5 + 9, OO = 2e18;

struct edge {
  int from, to;
  ll dist, time;
  edge(int from, int to, ll time, ll dist) {
    this->from = from;
    this->to = to;
    this->dist = dist;
    this->time = time;
  }
  bool operator < (const edge& e) const {
    if(time == e.time)
      return dist > e.dist;
    return time > e.time;
  }
};

int main() {
  fastIO;
//  freopen("input.in", "rt", stdin); // freopen("output.in", "wt", stdout);
  int t;
  cin >> t;
  while(t--) {
    int n, m, a, b;
    ll c, d;
    cin >> n >> m;
    vector<edge> vec[n + 2];
    for (int i = 0; i < m; ++i) {
      cin >> a >> b >> c >> d;
      vec[a].push_back(edge(a, b, c, d));
      vec[b].push_back(edge(b, a, c, d));
    }
    for (int i = 1; i <= n; ++i)
      sort(vec[i].rbegin(), vec[i].rend());
    sort(vec[n+1].rbegin(), vec[n+1].rend());
    int q;
    cin  >> q;
    while(q--) {
      int src, end;
      cin >> src >> end;
      vector<ll> dist(n + 2, OO);
      vector<ll> time(n + 2, OO);
      dist[src] = 0, time[src] = 0;
      priority_queue<edge> q;
      q.push(edge(-1, src, 0, 0));
      while(!q.empty()) {
        edge e = q.top();
        q.pop();
        if(e.time > time[e.to]) // (or time == time && dist > dist
          continue;
        for(auto ee: vec[e.to]) {
          if((time[ee.to] > time[ee.from] + ee.time) || (time[ee.to] == time[ee.from] + ee.time && dist[ee.to] > dist[ee.from] + ee.dist)) {
            dist[ee.to] = dist[ee.from] + ee.dist;
            time[ee.to] = time[ee.from] + ee.time;
            q.push(edge(ee.from, ee.to, time[ee.to], dist[ee.to]));
          }
        }
      }
      if(time[end] == OO)
        cout << "No Path.\n";
      else
        cout << "Distance and time to reach destination is " << dist[end] << " & " << time[end] << ".\n";
    }
    if(t)
      cout << '\n';
  }
  return 0;
}

