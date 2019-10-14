#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "rt", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, M = 1e6 + 1, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 2e18;

ll arr[109][109], pre[109][109];

int main() {
  fastIO;
//  read("input.in");
//  write("output.in");
  int n;
  while (cin >> n) {
    clr(pre, 0);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        cin >> arr[i][j];

    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        pre[i][j] += pre[i][j - 1] + arr[i][j];
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        pre[i][j] += pre[i - 1][j];

    ll ans = -OO;
    for (int w = 1; w <= n; ++w) {
      for (int j = w; j <= n; ++j) {
        ll cur = 0;
        for (int i = 1; i <= n; ++i) {
          ll elm = pre[i][j] - pre[i][j - w] - pre[i - 1][j] + pre[i - 1][j - w];
          cur += elm;
          ans = max(ans, cur);
          if (cur < 0)
            cur = 0;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}

