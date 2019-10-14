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

ll cnt[109][109];
ll kd[109][109];

int main() {
  fastIO;
//  read("input.in");
//  write("output.in");
  int t;
  cin >> t;
  while(t--) {
    clr(cnt, 0);
    int n, s, r1, c1, r2, c2;
    cin >> n >> s;
    for (int i = 0; i < s; ++i) {
      cin >> r1 >> c1 >> r2 >> c2;
      for (int j = r1; j <= r2; ++j) {
        ++cnt[j][c1];
        --cnt[j][c2 + 1];
      }
    }

    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        cnt[i][j] += cnt[i][j - 1];

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if(cnt[i][j])
          kd[i][j] = -OO;
        else
          kd[i][j] = 1;
      }
    }

    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        kd[i][j] += kd[i][j-1];

    ll total = 0;
    for (int w = 1; w <= n; ++w) {
      for (int j = w; j <= n; ++j) {
        ll cur = 0;
        for (int i = 1; i <= n; ++i) {
          ll elm = kd[i][j] - kd[i][j - w];
          cur += elm;
          if(cur > total)
            total = cur;
          if(cur < 0)
            cur = 0;
        }
      }
    }
    cout << total << '\n';
  }
  return 0;
}

