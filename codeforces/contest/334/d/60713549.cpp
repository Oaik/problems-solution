#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e3 + 9, M = 3e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

bool noX[N], noY[N];

int main() {
  fastIO;
  int n, m, x, y;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    noX[x] = 1;
    noY[y] = 1;
  }
  int ans = 0;
  for (int i = 2; i < n; ++i) {
    if(!noX[i]) ++ans;
    if(!noY[i]) ++ans;
  }
  if((n&1) && !noX[(n+1) / 2] && !noY[(n+1) / 2])
    --ans;
  cout << ans;
  return 0;
}
