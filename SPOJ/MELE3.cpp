#include<bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define ll long long
#define fastIO cout << fixed << setprecision(9), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 2e5 + 9, M = 2e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

vector<int> adj[N];

struct edge {
  ll tt;
  int from, to;
  edge(ll _tt, int _from, int _to) {
    tt = _tt, from = _from, to = _to;
  }
  bool operator <(const edge &e) const {
    return tt > e.tt;
  }
};

int main() {
  fastIO;
#ifdef LOCAL
      freopen("input.in", "rt", stdin);
#endif
      int n,
  m, u, v;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  priority_queue<edge> q;
  vector<ll> dist(n + 1, inf);
  q.push(edge(0, -1, 1));
  dist[1] = 0;
  while (!q.empty()) {
    edge e = q.top();
    q.pop();
    if (e.tt > dist[e.to])
      continue;
    for (int it : adj[e.to]) {
      if (it > e.to) {
        if(!e.tt) {
          ll cur = (it - e.to) * 5;
          dist[it] = cur;
          q.push(edge(e.tt + cur, e.to, it));
          continue;
        }
        ll cur = (it - e.to) * 5;
        if(((e.tt/5) % (it - e.to))) {
          cur += ( (it - e.to) - ((e.tt/5) % (it - e.to))) * 5ll;
          if (!(((e.tt/5) / (it - e.to)) & 1))
            cur += (it - e.to) * 5;
        } else {
          if ((((e.tt/5) / (it - e.to)) & 1))
            cur += (it - e.to) * 5;
        }
        if (cur + e.tt < dist[it]) {
          dist[it] = cur + e.tt;
          q.push(edge(e.tt + cur, e.to, it));
        }
      } else {
        if(!e.tt) {
          ll cur = (e.to - it) * 5;
          dist[it] = cur;
          q.push(edge(e.tt + cur, e.to, it));
          continue;
        }
        ll cur = (e.to - it) * 5;
        if(((e.tt/5) % (e.to - it) )) {
          cur += ( (e.to - it) - ((e.tt/5) % (e.to - it) )) * 5ll;
          if (!(((e.tt/5) / (e.to - it)) & 1))
            cur += (e.to - it) * 5;
        } else {
          if ((((e.tt/5) / (e.to - it)) & 1))
            cur += (e.to - it) * 5;
        }
        if (cur + e.tt < dist[it]) {
          dist[it] = cur + e.tt;
          q.push(edge(e.tt + cur, e.to, it));
        }
      }
    }
  }
  cout << dist[n];
  return 0;
}

