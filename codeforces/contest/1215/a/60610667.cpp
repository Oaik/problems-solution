#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 3e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

int main() {
  fastIO;
  int a, b, x, y;
  int n, m;
  cin >> a >> b >> x >> y >> n;
  m = n;
  int tempa = a, tempb = b;
  int mn = 0;
  if(x < y) {
    while(n >= x && tempa) {
      n -= x;
      --tempa;
      ++mn;
    }
    while(n >= y && tempb) {
      n -= y;
      --tempb;
      ++mn;
    }
  } else {
    while(n >= y && tempb) {
      n -= y;
      --tempb;
      ++mn;
    }
    while(n >= x && tempa) {
      n -= x;
      --tempa;
      ++mn;
    }
  }
  n = m;
  int mx = 0;
  int cur = a * (x - 1) + b * (y - 1);
  mx = max(0, n - cur);
  cout << mx << ' ' << mn;
  return 0;
}
