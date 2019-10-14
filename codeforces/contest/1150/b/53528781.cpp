#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  // freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(4);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
int const N = 1e6 + 9, M = 1e5 + 9, OO = 1e9;

char arr[59][59];
int n, dx[] = {0,0,1,-1}, dy[] = {1, -1, 0, 0};
bool valid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
  debug();
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
    }
  }
  int cnt;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if(arr[i][j] == '#')
        continue;
      cnt = 0;
      for (int k = 0; k < 4; ++k) {
        int nx = i + dx[k], ny = j + dy[k];
        if(!valid(nx, ny) || arr[nx][ny] == '#')
          continue;
        ++cnt;
      }
      if(cnt == 4) {
        arr[i][j] = '#';
        for (int k = 0; k < 4; ++k) {
          int nx = i + dx[k], ny = j + dy[k];
          arr[nx][ny] = '#';
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if(arr[i][j] == '.') {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
}