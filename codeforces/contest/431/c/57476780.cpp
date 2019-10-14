#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(10), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
double const EPS = 1e-8, PI = acos(-1);
const int N = 100 + 9, OO = 1e9;
int n, k, d;
ll mem[N][N][2];
ll const MOD = 1e9 + 7;

ll DP(int sum, int taken, int can) {
  if(sum > n)
    return 0;
  if(sum == n) {
    if(can)
      return 1;
    return 0;
  }
  ll& ret = mem[sum][taken][can];
  if(~ret)
    return ret;
  ret = 0;
  for (int i = 1; i <= k; ++i) {
    if(i <= n - sum)
      ret = ( (ret % MOD) + (DP(sum + i, taken + 1, (can) ? can : (i >= d))) % MOD ) % MOD;
  }
  return (ret % MOD);
}

int main() {
  fastIO;
  cin >> n >> k >> d;
  clr(mem, -1);
  cout << DP(0, 0, 0);
  return 0;
}
