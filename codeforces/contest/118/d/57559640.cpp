#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(10), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
double const EPS = 1e-8, PI = acos(-1);
const int N = 3e5 + 9, OO = 1e9;

int n, m, a, b;
ll mem[101][101][11][11];
ll const MOD = 1e8;

ll DP(int x, int y, int cnt1, int cnt2) {
  if (x == 0 && y == 0)
    return 1;
  ll& ret = mem[x][y][cnt1][cnt2];
  if (~ret)
    return ret;
  ret = 0;
  if(cnt1 + 1 <= a && x > 0)
      ret = ((ret % MOD) + (DP(x - 1, y, cnt1 + 1, 0)) % MOD) % MOD;
  if(cnt2 + 1 <= b && y > 0)
      ret = ( (ret % MOD) + (DP(x, y - 1, 0, cnt2 + 1) % MOD)) % MOD;
  return ret;
}

int main() {
  fastIO;
  cin >> n >> m >> a >> b;
  clr(mem, -1);
  ll c1 = DP(n, m, 0, 0) % MOD;
  cout << c1;
  return 0;
}
