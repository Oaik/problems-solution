#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout << fixed << setprecision(3)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1.5 * (1e7 + 9), OO = 1e9, v = 1e6;

vector<int> vec, vv;

int main() {
  fastIO;
//  freopen("input.in", "rt", stdin); // freopen("output.in", "wt", stdout);
  int n, m, a, b, c;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    vec.push_back(a);
  }
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    if(a > 1)
      continue;
    vv.push_back(b);
  }
  sort(all(vec));
  sort(vv.rbegin(), vv.rend());
  int ans = 1e9;
  for (int i = 0; i <= n; ++i) {
    if(i == n) {
      int it = upper_bound(all(vv), OO, greater<int>()) - vv.begin();
      ans = min(ans, it + i);
    } else {
      int it = upper_bound(all(vv), vec[i], greater<int>()) - vv.begin();
      ans = min(ans, it + i);
    }
  }
  cout << ans;
  return 0;
}
