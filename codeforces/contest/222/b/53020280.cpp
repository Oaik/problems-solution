#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define all(v)    ((v).begin()),((v).end())
#define clr(a,b)  memset(a,b,sizeof(a))
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);
// freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int const N = 2e5 + 9, OO = 1e9;

int arr[1001][1001];

int col[1001], row[1001];

int main() {
  debug();
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
    }
  }
  iota(col, col + 1001, 0);
  iota(row, row + 1001, 0);
  int a,b, temp;
  char c;
  for (int i = 0; i < k; ++i) {
    cin >> c >> a >> b;
    --a, --b;
    if(c == 'r') {
      temp = row[a];
      row[a] = row[b];
      row[b] = temp;
//      for (int j = 0; j < m; ++j) {
//        swap(arr[a][j], arr[b][j]);
//      }
    } else if(c == 'c') {
      temp = col[a];
      col[a] = col[b];
      col[b] = temp;
//      for (int j = 0; j < n; ++j) {
//        swap(arr[j][a], arr[j][b]);
//      }
    } else {
      cout << arr[row[a]][col[b]] << '\n';
    }
  }
  return 0;
}
