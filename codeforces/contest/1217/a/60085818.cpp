#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 1e6 + 9, OO = 1e9 + 9, MOD = 1e9 + 7;

int main() {
  fastIO
  ll t;
  cin >> t;
  while(t--) {
    int a, b, c;
    cin >> a >> b >> c;
    ll start = 0, end = c, ans = OO, mid;
    while(start <= end) {
      mid = start + (end - start) / 2;
      if(a + mid > b + (c - mid)) {
        ans = mid;
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }

    if(ans == OO)
      ans = 0;
    else
      ans = c - ans + 1;
    cout << ans << '\n';
  }
  return 0;
}
