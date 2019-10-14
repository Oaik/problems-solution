#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define rall(v) ((v).rbegin()),((v).rend())
#define read(v) freopen(v, "rt", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(2), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 5e5 + 9, M = 1e6 + 1, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e16;

int vis[20][20][(1 << 10)];
char path[20][20];
int bombs[20][20], dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
int h, w, sX, sY, bombCnt = 0, vid = 1;

bool valid(int x, int y) {
  return x >= 0 && x < w && y >= 0 && y < h;
}

int main() {
  fastIO;
//  read("input.in");
//  write("output.in");
  while (cin >> h >> w, h && w) {
    bombCnt = 0, ++vid;
    for (int i = 0; i < w; ++i) {
      for (int j = 0; j < h; ++j) {
        cin >> path[i][j];
        if (path[i][j] == 'o')
          sX = i, sY = j;
        else if (path[i][j] == '*')
          bombs[i][j] = bombCnt++;
      }
    }
    queue<pair<pair<int, int>, int>> q;
    q.push( { { sX, sY }, 0 });
    vis[sX][sY][0] = vid;
    int sz = 0, lvl = 0;
    bool can = 0;
    while (!q.empty() && !can) {
      sz = q.size();
      while (sz-- && !can) {
        auto it = q.front();
        if (it.second == (1 << bombCnt) - 1) {
          cout << lvl << '\n';
          can = 1;
          break;
        }
        q.pop();
        for (int i = 0; i < 4; ++i) {
          int nx = it.first.first + dx[i], ny = it.first.second + dy[i];
          if (!valid(nx, ny) || vis[nx][ny][it.second] == vid || path[nx][ny] == 'x')
            continue;
          if (path[nx][ny] == '*') {
            vis[nx][ny][it.second] = vid;
            q.push( { { nx, ny }, it.second | (1 << bombs[nx][ny]) });
            vis[nx][ny][it.second | (1 << bombs[nx][ny])] = vid;
          } else {
            vis[nx][ny][it.second] = vid;
            q.push( { { nx, ny }, it.second });
          }
        }
      }
      ++lvl;
    }
    if (!can)
      cout << -1 << '\n';
  }
  return 0;
}

