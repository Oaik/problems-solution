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
const int N = 2e6 + 9, OO = 1e9;

ll arr[101];

int main() {
  debug();
  int q;
  cin >> q;
  while (q--) {
    ll k, n, a, b;
    cin >> k >> n >> a >> b;
    ll co = (k / b) - (k % b == 0);
    if (co < n) {
      cout << -1 << '\n';
      continue;
    }
    bool can = 0;
    ll start = 0, end = n, mid, nn, sum, ans = 0;
    while(start <= end) {
      mid = start + (end - start) / 2;
      nn = n - mid;
      sum = mid * a + nn * b;
      if(sum < k) {
        ans = max(ans, mid);
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    cout << ans << '\n';
  }
}