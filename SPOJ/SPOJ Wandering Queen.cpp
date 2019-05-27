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
const int N = 1e3 + 9, OO = 1e9 + 9;

char arr[N][N];
int d[N][N], mask[N][N], n, m;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

bool valid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int BFS(int xstart, int ystart,int xend, int yend) {
  d[xstart][ystart] = 0;
  mask[xstart][ystart] = (1 << 8) - 1;
  queue<pair<int, int>> pts;
  pts.push({xstart, ystart});
  while(!pts.empty()) {
    int x = pts.front().first, y = pts.front().second;
    if(x == xend && y == yend) {
      return d[x][y];
    }
    pts.pop();
    for (int i = 0; i < 8; ++i) {
      int inc = 1;
      while(1) {
        int nx = x + dx[i] * inc, ny = y + dy[i] * inc;
        if(valid(nx, ny) && arr[nx][ny] != 'X' && !(mask[nx][ny] & (1 << i))) {
          if(d[nx][ny] == 0) {
            d[nx][ny] = d[x][y] + 1;
            pts.push({nx, ny});
          }
          mask[nx][ny] |= (1 << i);
        } else
          break;
        ++inc;
      }
    }
  }
  return -1;
}

int main() {
  debug();
  int t;
  cin >> t;
  while(t--) {
    int xstart, ystart, xend, yend;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> arr[i][j];
        d[i][j] = 0, mask[i][j] = 0;
        if(arr[i][j] == 'S')
          xstart = i, ystart = j;
        if(arr[i][j] == 'F')
          xend = i, yend = j;
      }
    }
    cout << BFS(xstart, ystart, xend, yend) << endl;
  }
  return 0;
}

