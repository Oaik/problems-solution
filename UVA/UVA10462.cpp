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
const int N = 2e5 + 9, OO = 1e9;

int sz[109], par[109];

int find(int x) {
  if (x == par[x])
    return x;
  return par[x] = find(par[x]);
}

bool join(int x, int y) {
  x = find(x), y = find(y);
  if (x == y)
    return 0;
  if (sz[x] < sz[y])
    swap(x, y);
  par[y] = x;
  sz[x] += sz[y];
  return 1;
}

int main() {
  debug();
  int t;
  cin >> t;
  for (int k = 1; k <= t; ++k) {
    int n, m, u, v, c;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> vec;
    vector<int> ans;
    for (int i = 0; i < m; ++i) {
      cin >> u >> v >> c;
      vec.push_back({c, {u, v}});
    }
    iota(par + 1, par + n + 1, 1);
    clr(sz, 0);
    int cnt = 0, totalCost = 0;
    sort(all(vec));
    for (int i = 0; i < (int)vec.size(); ++i) {
      if (join(vec[i].second.first, vec[i].second.second)) {
        totalCost += vec[i].first;
        ++cnt;
        ans.push_back(i);
      }
    }
    if (cnt == n - 1) {
      bool can = 0;
      int secondCost = 1e9;
      for (int i = 0; i < (int) ans.size(); ++i) {
        clr(sz, 0);
        iota(par + 1, par + n + 1, 1);
        cnt = 0, totalCost = 0;
        for (int j = 0; j < (int)vec.size(); ++j) {
          if(ans[i] == j)
            continue;
          if (join(vec[j].second.first, vec[j].second.second)) {
            totalCost += vec[j].first;
            ++cnt;
          }
        }
        if (cnt == n - 1 && cnt) {
          secondCost = min(secondCost, totalCost);
          can = 1;
        }
      }
      if (!can)
        cout << "Case #" << k << ' ' << ':' << ' ' << "No second way" << endl;
      else
        cout << "Case #" << k << ' ' << ':' << ' ' << secondCost << endl;
    } else {
      cout << "Case #" << k << ' ' << ':' << ' ' << "No way" << endl;
    }
  }
  return 0;
}

