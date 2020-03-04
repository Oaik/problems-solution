#include<bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define ll long long
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 2e4 + 9, M = 2e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

struct edge {
  int from, to;
  ll length, cost;
} ee;

vector<edge> adj[N];
ll ans = inf, mem[109][N];
int n, m, u, v, cost, tt, k;

ll solve(int node, int rem) {
  if(node == n)
    return 0;
  ll& ret = mem[node][rem];
  if(~ret)
    return ret;
  ret = inf;
  for(auto it: adj[node]) {
    if(it.cost <= rem)
      ret = min(ret, it.length + solve(it.to, rem - it.cost));
  }
  return ret;
}

int main() {
  fastIO;
#ifdef LOCAL
  freopen("input.in", "rt", stdin);
#endif
  int tc;
  cin >> tc;
  while(tc--) {
    cin >> k >> n >> m;
    for (int i = 0; i < m; ++i) {
      cin >> u >> v >> tt >> cost;
      ee = {u, v, tt, cost};
      adj[u].push_back(ee);
    }
    memset(mem, -1, sizeof mem);
    ans = solve(1, k);
    if(ans == inf)
      ans = -1;
    cout << ans << '\n';
    for (int i = 1; i <= n; ++i)
      adj[i].clear();
  }
  return 0;
}

