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
  cout << fixed << setprecision(12);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, OO = 1e9;

vector<double> res, len;

int main() {
  debug();
  int n, p, l, r;
  double ans = 0, cnt;
  cin >> n >> p;
  for (int i = 0; i < n; ++i) {
    cin >> l >> r;
    len.push_back((r - l) + 1);
    if(l % p != 0)
      l = l - (l % p) + p;
    r -= (r % p);
    if(r < l)
      res.push_back(0);
    else
      res.push_back(((r - l) / p) + 1);
  }
  for (int i = 0; i < n; ++i) {
    cnt = ((len[i] - res[i]) / len[i]) * ((len[(i + 1) % n] - res[(i + 1) % n]) / len[(i + 1) % n]);
    cnt = 1 - cnt;
    ans += cnt * 2000;
  }
  cout << ans;
  return 0;
}
