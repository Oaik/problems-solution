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

ll cost[N][N];
ll costX[N], costY[N];

int main() {
  fastIO;
//  read;
  clock_t startTime = clock();
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> cost[i][j];
      costX[i] += cost[i][j];
      costY[j] += cost[i][j];
    }
  }

  ll X = inf, Y = inf, mn1 = inf, mn2 = inf;
  for (int i = 0; i <= n; ++i) {
    int iterX = 4 * i;
    ll sum = 0;
    for (int j = 0; j < n; ++j) {
      int nwX = (4 * j) + 2;
      sum += (ll)(nwX-iterX) * (ll)(nwX-iterX) * costX[j];
    }
    if(sum < mn1)
      mn1 = sum, X = i;
  }

  for (int i = 0; i <= m; ++i) {
    int iterY = 4 * i;
    ll sum = 0;
    for (int j = 0; j < m; ++j) {
      int nwY = (4 * j) + 2;
      sum += (ll)(nwY-iterY) * (ll)(nwY-iterY) * costY[j];
    }
    if(sum < mn2)
      mn2 = sum, Y = i;
  }
  cout << mn1 + mn2 << '\n';
  cout << X << ' ' << Y << '\n';
  clock_t endTime = clock();
  cerr << endl << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;
  return 0;
}
