#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, M = 2e5 + 2, OO = 1e9 + 9, MOD = 1e9 + 7;

vector<pair<int, int>> vec[N];
vector<pair<int, int>> qq;
ll ans[N], par[N], sz[N];
ll res = 0;

int find(int x) {
  if(x == par[x]) return x;
  return par[x] = find(par[x]);
}

void join(int x, int y) {
  x = find(x), y = find(y);
  if(x == y)
    return;
  if(sz[x] < sz[y]) swap(x, y);
  res += (1ll * (sz[x] + sz[y]) * (sz[x] + sz[y] + 1)) / 2;
  res -= (1ll * sz[x] * (sz[x] + 1)) / 2;
  res -= (1ll * sz[y] * (sz[y] + 1)) / 2;
  sz[x] += sz[y];
  par[y] = x;
}

int main() {
  fastIO
  int n, m;
  cin >> n >> m;
  int u, v, c, mx = 0;
  --n;
  for (int i = 0; i < n; ++i) {
    cin >> u >> v >> c;
    par[u] = u, par[v] = v, sz[u] = sz[v] = 1;
    vec[c].push_back({u, v});
    mx = max(mx, c);
  }
  int rank;
  for (int i = 1; i <= M; ++i) {
    for(auto it: vec[i])
      join(it.first, it.second);
    ans[i] = res;
  }
  for (int i = 0; i < m; ++i) {
    cin >> rank;
    cout << ans[rank] << ' ';
  }
  return 0;
}
