#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "rt", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(2), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 1e6 + 1, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 2e18;

pair<int, int> pts[24];
int gg[21][21], n, k;

void preprocessing() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if(i == j)
        continue;
      int mask = (1 << i);
      mask |= (1 << j);
      for (int k = 0; k < n; ++k) {
        if (i == k || j == k)
          continue;
        int X1 = pts[j].first - pts[i].first,
            Y1 = pts[j].second - pts[i].second,
            X2 = pts[k].first - pts[i].first,
            Y2 = pts[k].second - pts[i].second;
        if (X1*Y2 - Y1*X2 != 0)
          continue;
        mask |= (1 << k);
      }
      gg[i][j] = mask;
    }
  }
}

int mem[(1 << 21)];

int solve(int mask) {
  if (__builtin_popcount(mask) >= k || mask == (1 << n) - 1)
    return 0;
  int &ret = mem[mask];
  if (~ret)
    return ret;
  ret = OO;
  vector<int> vec;
  for (int i = 0; i < n; ++i) {
    if ((mask & (1 << i)))
      continue;
    vec.push_back(i);
  }
  for (int i = 0; i < (int)vec.size(); ++i)
    for (int j = i + 1; j < (int)vec.size(); ++j)
      ret = min(ret, solve(mask | gg[vec[i]][vec[j]]) + 1);
  if (ret == OO)
    ret = 1;
  return ret;
}

int main() {
  fastIO;
//  read("input.in");
//  write("output.in");
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    if(i != 1)
      cout << '\n';
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
      cin >> pts[i].first >> pts[i].second;
    clr(mem, -1);
    preprocessing();
    cout << "Case #" << i << ':' << '\n';
    cout << solve(0) << endl;
  }
  return 0;
}

