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
const int N = 2e5 + 9, OO = 1e9;

char arr[509][509];
bool vis[509][509];
bool dir[5];
int n, m, dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
bool valid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
  debug();
  cin >> n >> m;
  dir[0] = dir[1] = dir[2] = dir[3] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
    }
  }
  bool can = 0;
  int cnt = 0;
  for (int i = 1; i < n && !can; ++i) {
    for (int j = 0; j < m && !can; ++j) {
      if (arr[i][j] != '*')
        continue;
      cnt = 0;
      for (int k = 0; k < 4; ++k) {
        if (valid(dx[k] + i, dy[k] + j) && arr[i + dx[k]][j + dy[k]] == '*')
          ++cnt;
      }
      if (cnt == 4) {
        can = 1;
        int factor = 1;
        vis[i][j] = 1;
        while (can) {
          can = 0;
          for (int k = 0; k < 4; ++k) {
            if (!dir[k])
              continue;
            if (valid(dx[k] * factor + i, dy[k] * factor + j) && arr[i + dx[k] * factor][j + dy[k] * factor] == '*')
              can = 1, vis[i + dx[k] * factor][j + dy[k] * factor] = 1;
            else
              dir[k] = 0;
          }
          ++factor;
        }
        can = 1;
      }
    }
  }
  if (!can) {
    cout << "NO";
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (arr[i][j] == '*' && !vis[i][j]) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
  return 0;
}