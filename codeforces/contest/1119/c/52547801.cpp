#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)    ((v).begin()),((v).end())
#define clr(a,b)  memset(a,b,sizeof(a))
const double EPS = 1e-8, pi = acos(-1);
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  // freopen("output.in", "wt", stdout);
#endif
}

int const N = 5e2 + 9, OO = 1e9;

bool arr[N][N], arr2[N][N];

int diffCol[N], diffRow[N], col1[N], row1[N], col2[N], row2[N];

int main() {
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  debug();
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
      if(arr[i][j])
        ++col1[j], ++row1[i];
    }
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> arr2[i][j];
      if(arr2[i][j])
        ++col2[j], ++row2[i];
    }
//  int row = 0, col = 0;
  for (int i = 0; i < n; ++i) {
    if((row1[i] % 2) != (row2[i] % 2)) {
      cout << "NO";
      return 0;
//      ++row;
    }
  }
  for (int i = 0; i < m; ++i) {
    if((col1[i]%2)!= (col2[i]%2)) {
      cout << "NO";
      return 0;
//      ++col;
    }
  }
//  cout << row << " " << col << endl;
//  if(row % 2 == 0 && col % 2 == 0)
    cout << "YES";
//  else
//    cout << "NO";
  return 0;
}