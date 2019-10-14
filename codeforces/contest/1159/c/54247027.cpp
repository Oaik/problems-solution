#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
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
const int N = 1e5 + 9, OO = 1e9;

vector<int> vec;

int main() {
  debug();
  int n, m, a, mx = 0, mn = 1e9 + 1;
  ll total = 0;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    vec.push_back(a);
    total += (ll)a * (ll)m;
    mx = max(mx, a);
  }
  for (int i = 0; i < m; ++i) {
    cin >> a;
    total += a;
    mn = min(mn, a);
  }
  total -= (ll)mx * (ll)m;
  if(mn < mx)
    cout << -1;
  else if(mn == mx)
    cout << total;
  else {
    sort(all(vec), greater<int>());
    total += (mx - vec[1]);
    cout << total;
  }
  return 0;
}
