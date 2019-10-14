#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 1e5 + 10, OO = 1e9 + 9, MOD = 1e9 + 7;
ll t, k, mem[N][2];

ll DP(int idx, bool isW) {
  if(idx + 1 == N)
    return 1;
  if(idx + 1 > N)
    return 0;
  ll& ret = mem[idx][isW];
  if(~ret)
    return ret;
  ret = 0;
  ret = DP(idx + 1, 0) % MOD;
  ret += DP(idx + k, 1) % MOD;
  ret = ret % MOD;
  return ret;
}

ll pre[M];

int main() {
  fastIO;
  cin >> t >> k;
  clr(mem, -1);
  DP(0, 0);
  ll u, v;
  pre[(int)1e5+7] = DP((int)1e5+7, 0);
  for (int i = 1e5 + 6; i >= 0; --i)
    pre[i] += ((DP(i, 0) % MOD) + (pre[i + 1] % MOD)) % MOD;
  while(t--) {
    cin >> u >> v;
    v = 1e5 + 8 - v;
    u = 1e5 + 8 - u;
    ++u;
//    int x = DP(v, 0), y = DP(v, 1);
//    int a = DP(u, 0), b = DP(u, 1);
//    cout << x << ' ' << y << ' ' << a << ' ' << b << '\n';
    ll x = pre[u], y = pre[v];
//    cerr << y << ' ' << x << '\n';
    ll ans = (((y - x) % MOD) + MOD) % MOD;
    cout << ans << '\n';
  }
  return 0;
}
