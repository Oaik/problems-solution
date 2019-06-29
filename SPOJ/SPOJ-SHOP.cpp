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
const int N = 1e5 + 9, OO = 1e9;

int arr[25][25], dist[25][25];
int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
int n, h, sX, sY, eX, eY;
char c;
bool valid(int x, int y) {
  return x >= 0 && x < h && y >= 0 && y < n;
}

struct edge {
  int x, y, cost;
  bool operator < (const edge &e) {
    return cost > e.cost;
  }
  edge(int x, int to, int w) {
    this-> x = x;
    this->y = to;
    this->cost = w;
  }
};

int Dijkstra() {
  queue<edge> q;
  int nX, nY;
  q.push( edge(sX, sY, 0));
  clr(dist, '?');
  dist[sX][sY] = 0;
  while (!q.empty()) {
    edge e = q.front();
    q.pop();
    if(e.cost > dist[e.x][e.y])
      continue;
    for (int i = 0; i < 4; ++i) {
      nX = dx[i] + e.x, nY = e.y + dy[i];
      if(!valid(nX, nY) || arr[nX][nY] == -1)
        continue;
      if(dist[nX][nY] > arr[nX][nY] + dist[e.x][e.y]) {
        dist[nX][nY] = arr[nX][nY] + dist[e.x][e.y];
        q.push(edge(nX, nY, dist[nX][nY]));
      }
    }
  }
  return dist[eX][eY];
}

int main() {
  debug();
  while (cin >> n >> h, n && h) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> c;
        arr[i][j] = (c - '0');
        if (c == 'S')
          sX = i, sY = j, arr[i][j] = 0;
        if (c == 'D')
          eX = i, eY = j, arr[i][j] = 0;
        if (c == 'X')
          arr[i][j] = -1;
      }
    }
    cout << Dijkstra() << '\n';
  }
  return 0;
}

