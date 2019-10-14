#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  // freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(4);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
int const N = 1e6 + 9, M = 1e5 + 9, OO = 1e9;

int main() {
  debug();
  ll n, m, b,a, mn = 1e9, mx = 0;
  cin >> n >> m >> b;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    mn = min(a, mn);
  }
  for (int i = 0; i < m; ++i) {
    cin >> a;
    mx = max(mx, a);
  }
  if(mn >= mx) {
    cout << b;
    return 0;
  }
  ll cnt = b / mn;
  ll rem = b - (cnt * mn);
  ll total = rem + mx * cnt;
  cout << total;
}