#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "r", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 2e5 + 9, M = 1e2 + 9, OO = 1e8 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

int adj[M][M], secShortest[M][M], realAdj[M][M];

int main() {
  fastIO;
//  read("input.in");
//  write("input.in");
  int n, m, k, tc = 1;
  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        adj[i][j] = OO, secShortest[i][j] = OO, realAdj[i][j] = OO;
    for (int i = 0; i < n; ++i)
      adj[i][i] = 0;
    int u, v, c;
    for (int i = 0; i < m; ++i) {
      cin >> u >> v >> c;
      adj[u][v] = c, realAdj[u][v] = c;
      adj[v][u] = c, realAdj[v][u] = c;
    }
    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          adj[i][j] = min(adj[i][k] + adj[k][j], adj[i][j]);

    for (int start = 0; start < n; ++start) {
      for (int end = 0; end < n; ++end) {
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            int ans = adj[start][i] + realAdj[i][j] + adj[j][end];
            if(ans > adj[start][end])
              secShortest[start][end] = min(secShortest[start][end], ans);
          }
        }
      }
    }
    cout << "Set #" << tc++ << '\n';
    cin >> k;
    while(k--) {
      cin >> u >> v;
      int mn = secShortest[u][v];
      if(mn == OO){
        cout << '?' << '\n';
        continue;
      }
      cout << mn << '\n';
    }
  }
  return 0;
}

