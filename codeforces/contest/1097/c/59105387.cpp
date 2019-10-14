#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(2), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9;

map<int, int> mp1, mp2;

int main() {
  fastIO;
  int n, ans = 0;
  cin >> n;
  string str;
  for (int i = 0; i < n; ++i) {
    cin >> str;
    int cur = 0, mn = 0;
    for(char c: str) {
      if(c == '(')
        ++cur;
      else
        --cur;
      mn = min(cur, mn);
    }
    if(cur > 0 && mn >= 0) {
      ++mp1[cur];
    } else if(cur < 0 && cur <= mn) {
      ++mp2[-cur];
    } else if(cur == 0 && mn == 0)
      ++ans;
  }
  ans /= 2;
  for(auto it: mp1)
    ans += min(mp1[it.first], mp2[it.first]);
  cout << ans;
  return 0;
}
