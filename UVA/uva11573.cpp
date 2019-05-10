#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);   //freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-6, PI = acos(-1);
const int N = 1e3 + 9;
int arr[N][N];
int dist[N][N];
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 }, dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int r, c;
bool valid(int x, int y) {
  return x >= 0 && x < r && y >= 0 && y < c;
}

int BFS(int startX, int startY, int endX, int endY) {
  memset(dist, '?', sizeof dist);
  dist[startX][startY] = 0;
  deque<pair<int, int>> dq;
  dq.push_back(make_pair(startX, startY));
  while (!dq.empty()) {
    pair<int, int> fnt = dq.front();
    dq.pop_front();
    for (int i = 0; i < 8; ++i) {
      int w = 1, nx = fnt.first + dx[i], ny = fnt.second + dy[i];
      if (!valid(nx, ny))
        continue;
      if (i == arr[fnt.first][fnt.second])
        w = 0;
      if (dist[nx][ny] > dist[fnt.first][fnt.second] + w) {
        dist[nx][ny] = dist[fnt.first][fnt.second] + w;
        if (w == 0) {
          dq.push_front(make_pair(nx, ny));
        } else {
          dq.push_back(make_pair(nx, ny));
        }
      }
    }
  }
  return dist[endX][endY];
}
int main() {
  debug();
  char ch;
  cin >> r >> c;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> ch;
      arr[i][j] = (ch - '0');
    }
  }
  int n, x1, y1, x2, y2;
  cin >> n;
  while (n--) {
    cin >> x1 >> y1 >> x2 >> y2;
    --x1, --x2, --y1, --y2;
    cout << BFS(x1, y1, x2, y2) << endl;
  }
  return 0;

}

