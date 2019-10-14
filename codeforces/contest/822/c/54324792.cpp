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
const int N = 2e5 + 9, OO = 2e9+9;

vector<pair<int, int>> lft[N];
vector<pair<int, int>> rr[N];
vector<int> res(N, OO);

int main() {
  debug();
  int n, m, u, v, c;
  ll ans = 2e9 + 9;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> u >> v >> c;
    lft[u].push_back({v, c});
    rr[v].push_back({u, c});
  }
  for (int i = 0; i <= N; ++i) {
    for(auto it: lft[i]) {
      if(it.first - i + 1 > m)
        continue;
      ans = min(ans, (ll)it.second + (ll)res[m - (it.first - i + 1)]);
    }
    for(auto it: rr[i]) {
      res[i - it.first + 1] = min(res[i - it.first + 1], it.second);
    }
  }
  if(ans == OO) ans = -1;
  cout << ans;
}
