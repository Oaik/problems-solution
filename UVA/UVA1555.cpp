#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "r", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(2), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 1e6 + 9, M = 2e3 + 9, OO = 1e9 + 7, MOD = 998244353;
const ll inf = 1e18;

int dcmp(double a, double b) {
  if (fabs(a - b) <= EPS)
    return 0;
  else if (a > b)
    return 1;
  else
    return -1;
}

int main() {
  fastIO;
//  read("input.in");
//  write("output.in");
  int n;
  double a;
  while (cin >> n >> a) {
    double start = 0, end = a, mid, ans;
    for (int i = 0; i < 30; ++i) {
      mid = (end + start) / 2.0;
      double cur = mid, last = a, val;
      for (int i = 2; i < n; ++i) {
        val = cur + cur - last + 2.0;
        last = cur;
        cur = val;
        if (dcmp(val, 0) == -1) {
          start = mid;
          break;
        }
        if (i == n - 1) {
          ans = val;
          end = mid;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}

