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

char arr[501][501];
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 }, n, m, k, cur = 0, s;
bool vis[501][501];

bool valid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

void DFS(int x, int y) {
  vis[x][y] = 1;
  ++cur;
  if(cur == s - k)
    return;
  for (int i = 0; i < 4; ++i) {
    int xx = x + dx[i], yy = y + dy[i];
    if (valid(xx, yy) && arr[xx][yy] == '.' && !vis[xx][yy] && cur != s - k)
      DFS(xx, yy);
  }
}

int main() {
  debug();
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
      s += (arr[i][j] == '.');
    }
  }
  bool found = 0;
  for (int i = 0; i < n && !found; ++i) {
    for (int j = 0; j < m && !found; ++j) {
      clr(vis, 0);
      if (arr[i][j] == '.' && !vis[i][j]) {
        cur = 0;
        DFS(i, j);
        if(cur == s - k)
          found = 1;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if(!vis[i][j] && arr[i][j] == '.')
        cout << 'X';
      else
        cout << arr[i][j];
    }
    cout << '\n';
  }
  return 0;
}
