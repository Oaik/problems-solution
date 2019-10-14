#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 3e5 + 9, M = 3e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18 + 9;

int n, h[N], p[N];
ll mem[N][3];

ll solve(int idx, int prv) {
  if (idx > n)
    return 0;
  ll& ret = mem[idx][prv];
  if (~ret)
    return ret;
  ret = inf;
  if (h[idx - 1] + prv != h[idx])
    ret = min(ret, solve(idx + 1, 0));
  if (h[idx - 1] + prv != h[idx] + 1)
    ret = min(ret, solve(idx + 1, 1) + p[idx]);
  if (h[idx - 1] + prv != h[idx] + 2)
    ret = min(ret, solve(idx + 1, 2) + p[idx] + p[idx]);
  return ret;
}

int main() {
  fastIO;
  int q;
  cin >> q;
  while (q--) {
    cin >> n;
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j < 3; ++j)
        mem[i][j] = -1;
    for (int i = 1; i <= n; ++i)
      cin >> h[i] >> p[i];
//    h[0] = -1, p[0] = -1;
    cout << solve(1, 0) << '\n';
  }
  return 0;
}
