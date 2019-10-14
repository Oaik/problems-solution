#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e2 + 9;
const ll OO = 1e18;
int cur[102], cost[102][102], n, m, k;
ll mem[102][102][102];
ll DP(int idx, int group, int prv) {
  if (idx == n) {
    if (group == k)
      return 0;
    else
      return OO;
  }
  ll &ret = mem[idx][group][prv];
  if (ret != -1)
    return ret;
  ret = OO;
  if (cur[idx] != 0) {
    ret = DP(idx + 1, group + (prv != cur[idx]), cur[idx]);
  } else {
    for (int i = 1; i <= m; ++i) {
      ret = min(ret, DP(idx + 1, group + (prv != i), i) + cost[idx][i]);
    }
  }
  return ret;
}
int main() {
  debug();
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i)
    cin >> cur[i];
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= m; ++j)
      cin >> cost[i][j];
  }
  clr(mem, -1);
  ll ans = DP(0, 0, m + 1);
  if (ans == OO)
    ans = -1;
  cout << ans;
  return 0;
}
