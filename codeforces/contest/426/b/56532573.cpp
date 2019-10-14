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
const int N = 5e5 + 9, OO = 1e9;

int arr[101][101];

int main() {
  debug();
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      cin >> arr[i][j];
  }
  int ans = n;
  while (n >= 2 && !(n & 1)) {
    int r = n >> 1;
    bool can = 1;
    for (int i = 0; i < r && can; ++i) {
      for (int j = 0; j < m && can; ++j) {
        if (arr[i][j] != arr[n - i - 1][j]) {
          can = 0;
          break;
        }
      }
    }
    if (!can)
      break;
    ans = r;
    n = n >> 1;
  }
  cout << ans;
  return 0;
}
