#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e6 + 9, OO = 1e9;
bool arr[100][100], rees[100][100];
int n1, m1;
int valid(int x, int y) {
  return x >= 0 && x < n1 && y >= 0 && y < m1;
}
int main() {
  fastIO;
  // freopen("input.in", "rt", stdin);//  freopen("output.in", "wt", stdout);
  int n0, m0;
  cin >> n0 >> m0;
  for (int i = 0; i < n0; ++i) {
    for (int j = 0; j < m0; ++j) {
      char c;
      cin >> c;
      arr[i][j] = (c == '1') ? 1 : 0;
    }
  }
  cin >> n1 >> m1;
  for (int i = 0; i < n1; ++i) {
    for (int j = 0; j < m1; ++j) {
      char c;
      cin >> c;
      rees[i][j] = (c == '1') ? 1 : 0;
    }
  }
  int ansX = 0, ansY = 0, ans = -OO, mxX = max(n1, n0), mxY = max(m1, m0);
  for (int i = -mxX; i < mxY; ++i) {
    for (int j = -mxY; j < mxY; ++j) {
      int res = 0;
      for (int k = 0; k < n0; ++k) {
        for (int w = 0; w < m0; ++w) {
          int x = k + i, y = w + j;
          if (valid(x, y)) {
            res += (arr[k][w] * rees[x][y]);
          }
        }
      }
      if (res > ans) {
        ans = res;
        ansX = i, ansY = j;
      }
    }
  }
  cout << ansX << ' ' << ansY;
  return 0;
}
