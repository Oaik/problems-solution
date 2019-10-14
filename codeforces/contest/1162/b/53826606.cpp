#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  //freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
int const N = 1e5 + 9, M = 1e5 + 9, OO = 1e9;

int n, m, arr[51][51],arr2[51][51], dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
bool valid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
  debug();
  cin >> n >> m;
  bool ans = 0, ret = 1;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i][0];
    if (i != 0)
      ret &= (arr[i][0] > arr[i - 1][0]);
    for (int j = 1; j < m; ++j) {
      cin >> arr[i][j];
      ret &= (arr[i][j] > arr[i][j - 1]);
      if (i != 0)
        ret &= (arr[i][j] > arr[i - 1][j]);
    }
  }
  for (int i = 0; i < n; ++i) {
    cin >> arr2[i][0];
    if (i != 0)
      ret &= (arr2[i][0] > arr2[i - 1][0]);
    for (int j = 1; j < m; ++j) {
      cin >> arr2[i][j];
      ret &= (arr2[i][j] > arr2[i][j - 1]);
      if (i != 0)
        ret &= (arr2[i][j] > arr2[i - 1][j]);
    }
  }
  if (ret) {
    cout << "Possible\n";
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if(arr[i][j] > arr2[i][j])
        swap(arr[i][j], arr2[i][j]);
    }
  }
  ret = 1;
  for (int i = 0; i < n; ++i) {
    if (i != 0) {
      ret &= (arr[i][0] > arr[i - 1][0]);
      ret &= (arr2[i][0] > arr2[i - 1][0]);
    }
    for (int j = 1; j < m; ++j) {
      ret &= (arr[i][j] > arr[i][j - 1]);
      ret &= (arr2[i][j] > arr2[i][j - 1]);
      if (i != 0) {
        ret &= (arr[i][j] > arr[i - 1][j]);
        ret &= (arr2[i][j] > arr2[i - 1][j]);
      }
    }
  }
  if (ret) {
    cout << "Possible\n";
    return 0;
  }
  cout << "Impossible";
}
