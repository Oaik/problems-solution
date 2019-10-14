#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9 + 9;

vector<ll> A, B;

int main() {
  debug();
  ll n, m, ta, tb, k, a;
  cin >> n >> m >> ta >> tb >> k;
  if(k >= n || k >= m) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    cin >> a;
    A.push_back(a + ta);
  }
  for (int i = 0; i < m; ++i) {
    cin >> a;
    B.push_back(a);
  }
  sort(all(A));
  sort(all(B));
  ll ans = -1;
  for (int i = 0; i < n; ++i) {
    if(i > k)
      break;
    auto it = lower_bound(B.begin(), B.end(), A[i]);
    if(it == B.end()) {
      cout << -1;
      return 0;
    }
    int idx = it - B.begin();
    int getIt = k - i + idx;
    if(getIt >= m) {
      cout << -1;
      return 0;
    }
    ans = max(ans, B[getIt] + tb);
  }
  cout << ans << endl;
  return 0;
}