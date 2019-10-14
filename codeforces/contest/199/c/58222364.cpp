#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, OO = 1e9;

int main() {
  fastIO;
  ll k, b, n, t;
  cin >> k >> b >> n >> t;
  ll x = 1;
  int ans = 0;
  while(x <= t) {
    x = k * x + b;
    ++ans;
  }
  cout << max(0ll, n - ans + 1);
  return 0;
}
