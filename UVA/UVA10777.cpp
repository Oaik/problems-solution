#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(2), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e2 + 9, OO = 1e9;

double ds[N];
int as[N];
int dcmp(double a, double b) {
  if (fabs(a - b) <= EPS)
    return 0;
  else if (a > b)
    return 1;
  else
    return -1;
}

int n;
double mem[10009];
double DP(int x = 0) {
  if (x == 10000)
    return 0;
  double &ret = mem[x];
  if(ret == ret)
    return ret;
  ret = 0;
  for (int i = 0; i < n; ++i) {
    bool ok = as[i] > 0;
    if(ok)
      ret += as[i] * ds[i];
    else
      ret += -1 * as[i] * ds[i] + ds[i] * DP(x+1);
  }
  return ret;
}

int main() {
  fastIO;
  double d;
  int a;
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cin >> n;
    double cur = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a >> d;
      as[i] = a, ds[i] = d;
      if (a > 0)
        cur += a * d;
    }
    cout << "Case " << i << ':' << ' ';
    if (dcmp(cur, 0) == 0) {
      cout << "God! Save me\n";
    } else {
      clr(mem, -1);
      cur = DP();
      cout << cur << '\n';
    }
  }
  return 0;
}

