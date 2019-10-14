#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, M = 50, OO = 1e9 + 9, MOD = 1e9 + 7;

ll cum[11];

int main() {
  fastIO
  int t;
  cin >> t;
  while(t--) {
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= 10; ++i) {
      cum[i] = cum[i-1] + (m * i) % 10;
    }
    n /= m;
    ll cyc = n / 10;
    ll rem = n % 10;
    cout << cum[10] * cyc + cum[rem] << '\n';
  }
  return 0;
}
