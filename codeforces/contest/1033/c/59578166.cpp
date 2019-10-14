#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 1e5 + 9, OO = 1e9 + 9, MOD = 1e9 + 7;

int ans[N], values[N], idxs[N];

int main() {
  fastIO;
  int n, a;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    idxs[a] = i;
    values[i] = a;
  }
  int cur = n, l, r, val;
  bool can;
  while(cur != 0) {
    l = idxs[cur] - cur, r = idxs[cur] + cur;
    can = 0;
    while(l >= 0) {
      val = values[l];
      if(val < cur || ans[val] == 2) {
        l -= cur;
        continue;
      }
      can = 1;
      break;
    }
    while(r < n && !can) {
      val = values[r];
      if(val < cur || ans[val] == 2) {
        r += cur;
        continue;
      }
      can = 1;
      break;
    }
    if(can)
      ans[cur] = 2;
    else
      ans[cur] = 1;
    --cur;
  }
  for (int i = 0; i < n; ++i) {
    val = values[i];
//    cerr << ans[val] << ' ';
    if(ans[val] == 1)
      cout << 'B';
    else
      cout << 'A';
  }
  return 0;
}
