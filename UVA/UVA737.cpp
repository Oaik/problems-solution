#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout << fixed << setprecision(0)
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e6 + 9, OO = 1e9, v = 1e6;

int main() {
  fastIO;
//  freopen("input.in", "rt", stdin);
  int t;
  while(cin >> t, t) {
    int X1 = -OO, X2 = OO, Y1 = -OO, Y2 = OO, Z1 = -OO, Z2 = OO;
    while(t--) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      X1 = max(X1, a);
      Y1 = max(Y1, b);
      Z1 = max(Z1, c);
      X2 = min(X2, a + d);
      Y2 = min(Y2, b + d);
      Z2 = min(Z2, c + d);
    }
    if(X1 >= X2 || Y1 >= Y2 || Z1 >= Z2) {
      cout << 0 << '\n';
      continue;
    }
    int ans = (X2 - X1) * (Y2 - Y1) * (Z2 - Z1);
    cout << ans << '\n';
  }
  return 0;
}

