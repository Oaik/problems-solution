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
const int N = 1e2 + 9;
const ll OO = 2e18;

int main() {
  debug();
  int a, b, c, d, n;
  cin >> n >> a >> b >> c >> d;
  int val1 = a + b, val2 = a + c,val3 = b + d, val4 = c + d;
  int mn = min(val1, min(val2, min(val3, val4)));
  int mx = max(val1, max(val2, max(val3, val4)));
  ll ans = (ll)(n - (mx - mn));
  if(ans <= 0) {
    cout << 0;
  } else {
    ans *= n;
    cout << ans;
  }
  return 0;
}
