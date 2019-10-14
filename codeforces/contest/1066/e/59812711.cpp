#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, M = 2e5 + 2, OO = 1e9 + 9, MOD = 998244353;

ll power(ll x, ll y) {
    ll res = 1;
    x = x % MOD;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % MOD;
        y = y>>1;
        x = (x*x) % MOD;
    }
    return res % MOD;
}

deque<char> sA,sB;
int pre[N];

int main() {
  fastIO
  int n, m;
  cin >> n >> m;
  char c;
  for (int i = 0; i < n; ++i) {
    cin >> c;
    sA.push_back(c);
  }
  for (int i = 0; i < m; ++i) {
    cin >> c;
    sB.push_back(c);
  }
  int k = max(n, m);
  if(k > n) {
    int diff = k - n;
    while(diff--)
      sA.push_front('0');
  }
  if(k > m) {
    int diff = k - m;
    while(diff--)
      sB.push_front('0');
  }
  reverse(all(sB));
  reverse(all(sA));
  for (int i = 1; i <= k; ++i)
    pre[i] += pre[i-1] + (sB[i - 1] == '1');
  ll ans = 0;
  for (int i = 1; i <= k; ++i) {
    if(sA[i - 1] == '0')
      continue;
    ll pw = power(2, i - 1);
    ll kam = pre[k] - (pre[i-1]);
    ans = (ans + pw * kam) % MOD;
  }
  cout << ans % MOD;
  return 0;
}
