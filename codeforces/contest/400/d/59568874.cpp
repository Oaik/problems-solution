#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 509, M = 1e5 + 9, OO = 1e9 + 9, MOD = 1e9 + 7;

int dp[N][N];
int arr[M], kam[N];

bool vis[M];
vector<int> vec[M];
void DFS(int x) {
  vis[x] = 1;
  for(int it: vec[x]) {
    if(vis[it])
      continue;
    DFS(it);
  }
}

int main() {
  fastIO;
  int n, m, t, cnt = 0, prv = 1, a;
  cin >> n >> m >> t;
  for (int i = 1; i <= t; ++i) {
    cin >> a;
    cnt += a;
    for (; prv <= cnt; ++prv)
      arr[prv] = i;
    kam[i] = a;
  }
  for (int i = 1; i <= t; ++i)
    for (int j = 1; j <= t; ++j)
      dp[i][j] = OO;
  int u, v, c, realU, realV;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> c;
    realU = arr[u], realV = arr[v];
    dp[realU][realV] = dp[realV][realU] = min(dp[realU][realV], c);
    if(c)
      continue;
    vec[u].push_back(v);
    vec[v].push_back(u);
  }
  for (int k = 1; k <= t; ++k)
    for (int i = 1; i <= t; ++i)
      for (int j = 1; j <= t; ++j)
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
  bool can = 1;
  int cur = 1, lim = 0;
  for (int i = 1; i <= t && can; ++i) {
    clr(vis, 0);
    DFS(cur);
    lim += kam[i];
    for (;cur<= lim; ++cur) {
      if(!vis[cur]) {
        can = 0;
        break;
      }
    }
  }
  if(can) {
    cout << "Yes\n";
    for (int i = 1; i <= t; ++i)
      dp[i][i] = 0;
    for (int i = 1; i <= t; ++i) {
      for (int j = 1; j <= t; ++j) {
        if(dp[i][j] == OO)
          dp[i][j] = -1;
        cout << dp[i][j] << ' ';
      }
      cout << '\n';
    }
  } else
    cout << "No\n";
  return 0;
}
