#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e6 + 9, M = 1e6 + 19, OO = 1e9 + 9, MOD = 1e9 + 7;

int ans[1001][1001];

int main() {
  fastIO;
  int n, a;
  cin >> n;
//  int res = -1;
//  for (int i = 0; i < n; ++i) {
//    cin >> a;
//    if(res == -1)
//      res = a;
//    else
//      res ^= a;
//  }
//  cout << res;
//  return 0;
  int cur = 0, nextE = 0, nextO = 1;
  for (int i = 0; i < n; ++i) {
    if(i & 1)
      cur = nextO;
    else
      cur = nextE;
    for (int j = 0; j < n; ++j) {
      ans[j][i] = cur;
      cur += 2;
    }
    if(i & 1)
      nextO = cur;
   else
      nextE = cur;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      cout << ans[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}
