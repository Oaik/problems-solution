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
const int N = 1e5 + 9, OO = 1e9;

int arr[109];

int main() {
  debug();
  int n, m, x;
  cin >> n >> m >> x;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
  int ans = 0, cnt = 0, val, mra = 0, e = 0, lft = 0, right = 0;
  for (int i = 2; i < n; ++i) {
    if (arr[i] == x && arr[i] == arr[i + 1]) {
      mra = 2;
      if (arr[i + 2] == arr[i - 1])
        val = arr[i + 2], lft = i - 1, right = i + 2;
      while (val != 0) {
        val = arr[right];
        cnt = 0, e = 0;
        for (; right <= n; ++right) {
          if (arr[right] == val)
            ++cnt, e = 2;
          else
            break;
        }
        for (; lft > 0; --lft) {
          if (arr[lft] == val)
            ++cnt, e += 2;
          else
            break;
        }
        if (cnt >= 3 && e >= 4)
          mra += cnt;
        else
          break;
      }
      ans = max(ans, mra);
    }
  }
  cout << ans;
  return 0;
}
