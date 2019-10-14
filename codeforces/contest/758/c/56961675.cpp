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
//  freopen("input.in", "rt", stdin); // freopen("output.in", "wt", stdout);
  ll n, m, k, x, y;
  cin >> n >> m >> k >> x >> y;
  ll arr[n][m];
  --x, --y;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      arr[i][j] = 0;
  if(n == 1) {
    ll factor = k / m;
    for (int i = 0; i < m; ++i)
      arr[0][i] += factor;
    k -= (factor * m);
    for (int i = 0; i < m && k; ++i)
      arr[0][i]++, --k;
    ll mx = 0, mn = 2e18;
    for (int i = 0; i < m; ++i)
      mx = max(mx, arr[0][i]), mn = min(mn, arr[0][i]);
    cout << mx << ' ' << mn << ' ' << arr[x][y];
    return 0;
  }
  ll firstLp = min(n * m, k);
  k -= firstLp;
  for (int i = 0; i < n && firstLp; ++i)
    for (int j = 0; j < m && firstLp; ++j)
      ++arr[i][j],--firstLp;
  ll secondLp = min((n - 1) * m, k);
  k -= secondLp;
  for (int i = n-2; i >= 0 && secondLp; --i)
    for (int j = 0; j < m && secondLp; ++j)
      ++arr[i][j],--secondLp;
  secondLp = min((n - 1) * m, k);
  k -= secondLp;
  for (int i = 1; i < n && secondLp; ++i)
    for (int j = 0; j < m && secondLp; ++j)
      ++arr[i][j],--secondLp;
  ll factor = k / ((n-1) * m), rem = k % ((n-1) * m);
  for (int i = n-2; i > 0; --i)
    for (int j = 0; j < m; ++j)
      arr[i][j] += factor;
  for (int i = 0; i < m; ++i)
    arr[0][i] += (factor / 2) + (factor & 1), arr[n-1][i] += (factor / 2);
  if(factor & 1) {
    for (int i = 1; i < n && rem; ++i)
      for (int j = 0; j < m && rem; ++j)
        ++arr[i][j],--rem;
  } else {
    for (int i = n-2; i >= 0 && rem; --i)
      for (int j = 0; j < m && rem; ++j)
        ++arr[i][j],--rem;
  }
  ll mx = 0, mn = 2e18;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      mx = max(mx, arr[i][j]), mn = min(mn, arr[i][j]);
  cout << mx << ' ' << mn << ' ' << arr[x][y];
  return 0;
}
