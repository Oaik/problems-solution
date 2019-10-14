#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(5), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9;

int main() {
  fastIO;
  ll n, m;
  int q;
  cin >> n >> m >> q;
  ll g = __gcd(n, m);
  n /= g, m /= g;
  ll x, y, a, b;
  for (int i = 0; i < q; ++i) {
    cin >> x >> y >> a >> b;
    if(x == 1) {
      if(a == 2) {
        if((y-1) / n == (b-1) / m)
          cout << "YES\n";
        else
          cout << "NO\n";
      } else {
        if((y-1) / n == (b-1) / n)
          cout << "YES\n";
        else
          cout << "NO\n";
      }
    } else {
      if(a == 1) {
        if((y-1) / m == (b-1) / n)
          cout << "YES\n";
        else
          cout << "NO\n";
      } else {
        if((y-1) / m == (b-1) / m)
          cout << "YES\n";
        else
          cout << "NO\n";
      }
    }
  }
  return 0;
}
