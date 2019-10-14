#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 3e5 + 9, M = 3e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18 + 9;

int color[101][101], n;
int dx[8] = { 2, 2, -2, -2, 1, 1, -1, -1 }, dy[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };

bool valid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < n;
}

queue<pair<int, int>> q;

int main() {
  fastIO;
  cin >> n;
  color[0][0] = 1;
  q.push({0, 0});
  while(!q.empty()) {
    int sz = q.size();
    while(sz--) {
      auto it = q.front();
      int cur = (color[it.first][it.second] == 1) ? 2 : 1;
      q.pop();
      for (int k = 0; k < 8; ++k) {
        int nx = it.first + dx[k], ny = it.second + dy[k];
        if (valid(nx, ny) && !color[nx][ny]) {
          color[nx][ny] = cur;
          q.push({nx, ny});
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      cout << ((color[i][j] == 1) ? 'W' : 'B');
    cout << '\n';
  }
  return 0;
}
