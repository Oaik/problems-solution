#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 3e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

int arr[5][101];
vector<pair<int, pair<int, int>>> vec;
vector<int> per;
int shiftCol[109];
int n, m, a;

int solve() {
  int row = 0, total = 0;
  clr(shiftCol, -1);
  for (int i = 0; i < (int)vec.size() && row < n; ++i) {
    int x = vec[i].second.first, y = vec[i].second.second;
    int rr = per[row], can;
    if(x < rr)
      can = rr - x;
    else
      can = (n - 1 - x) + (rr + 1);
    if(shiftCol[y] == -1) {
      shiftCol[y] = can;
      total += vec[i].first;
      ++row;
      continue;
    }
    if(shiftCol[y] == can) {
      total += vec[i].first;
      ++row;
    }
  }
  return total;
}

int main() {
  fastIO;
  int t;
  cin >> t;
  while(t--) {
    vec.clear();
    per.clear();
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        cin >> a, vec.push_back({a, {i, j}});
    sort(vec.rbegin(), vec.rend());
    for (int i = 0; i < n; ++i)
      per.push_back(i);
    int ans = 0;
    do {
      ans = max(ans, solve());
    } while(next_permutation(all(per)));
    cout << ans << '\n';
  }
  return 0;
}
