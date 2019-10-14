#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(5), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e6 + 9, OO = 1e9;
ll arr[109];
int main() {
  fastIO;
  int t;
  cin >> t;
  while(t--) {
    ll n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
      cin >> arr[i];
    bool can = 1;
    for (int i = 1; i < n; ++i) {
      if(arr[i] - k <= arr[i-1]) {
        m += arr[i-1] - max(arr[i] - k, 0ll);
      } else {
        if(arr[i] - k <= arr[i-1] + m) {
          int mm = max(arr[i] - k, 0ll);
          m -= abs(mm - arr[i-1]);
        } else {
          can = 0;
          break;
        }
      }
      if(m < 0) {
        can = 0;
        break;
      }
    }
    if(can)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
