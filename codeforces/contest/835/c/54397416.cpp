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
const int N = 2e5 + 9, OO = 2e9 + 9;

int arr[101][101][11];

int main() {
  debug();
  int t,n, q, c, x, y, s, x1, y1, cnt;
  cin >> n >> q >> c;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y >> s;
    ++arr[x][y][s];
  }
  for (int i = 1; i < 101; ++i) {
    for (int j = 1; j < 101; ++j) {
      for (int k = 0; k < 11; ++k) {
        arr[i][j][k] += arr[i-1][j][k];
      }
    }
  }
  for (int i = 1; i < 101; ++i) {
    for (int j = 1; j < 101; ++j) {
      for (int k = 0; k < 11; ++k) {
        arr[i][j][k] += arr[i][j-1][k];
      }
    }
  }
  ll total = 0;
  for (int i = 0; i < q; ++i) {
    cin >> t >> x >> y >> x1 >> y1;
    total = 0;
    for (int j = 0; j <= c; ++j) {
      int bb = (t + j) % (c + 1);
      cnt = arr[x1][y1][j] - arr[x1][y-1][j] - arr[x-1][y1][j] + arr[x-1][y-1][j];
      total += (bb) * cnt;
    }
    cout << total << endl;
  }
}
