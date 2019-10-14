#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, M = 1e6 + 1, OO = 1e9 + 1, MOD = 1e9 + 7;
const unsigned ll inf = 9e18;

int pre[49][49], mem[49][49][49][49];

int main() {
  fastIO
  int n, m, q;
  char ca;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
       cin >> ca;
       pre[i][j] = (ca == '1');
    }
  }

  clr(mem, -1);

  for (int i = 1; i <= n; ++i) // row pre
    for (int j = 1; j <= m; ++j)
      pre[i][j] += pre[i][j-1];
  for (int j = 1; j <= m; ++j) // col pre
    for (int i = 1; i <= n; ++i)
      pre[i][j] += pre[i-1][j];

  int a, b, c, d;
  for (int i = 0; i < q; ++i) {
    cin >> a >> b >> c >> d;
    int total = 0;
    for (int i = a; i <= c; ++i) {
      for (int j = b; j <= d; ++j) {
        if(~mem[i][j][c][d]) {
          total += mem[i][j][c][d];
          continue;
        }
        int ret = 0;
        for (int x = i; x <= c; ++x) {
          for (int y = j; y <= d; ++y) {
            total += (pre[x][y] - pre[x][j-1] - pre[i-1][y]  + pre[i-1][j-1]) == 0;
            ret += (pre[x][y] - pre[x][j-1] - pre[i-1][y]  + pre[i-1][j-1]) == 0;
          }
        }
        mem[i][j][c][d] = ret;
      }
    }
    cout << total << endl;
  }
  return 0;
}
