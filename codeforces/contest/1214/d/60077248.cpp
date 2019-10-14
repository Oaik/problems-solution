#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 2e5 + 2, OO = 1e9 + 9, MOD = 1e9 + 7;

int n, m, dx[2] = {0, 1}, dy[2] = {1, 0};

bool valid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

map<pair<int, int>, bool> mp;
vector<vector<char>> vec;

bool can;

bool DFS(int x, int y){
  if(!valid(x, y))
    return 0;
  if(x == n-1 && y == m-1) {
    can = 1;
    return 1;
  }
  if(x != 0 || y != 0)
    mp[{x, y}] = 1;
  for (int i = 0; i < 2; ++i) {
    int nX = x + dx[i], nY = y + dy[i];
    if(!valid(nX, nY) || vec[nX][nY] == '#')
      continue;
    if(mp.find({nX, nY}) != mp.end())
      continue;
    bool ans = DFS(nX, nY);
    if(ans)
      return ans;
  }
  return 0;
}

int main() {
  fastIO
  cin >> n >> m;
  vec = vector<vector<char>> (n, vector<char>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      cin >> vec[i][j];
  }
  if(!DFS(0, 0)) {
    cout << 0;
    return 0;
  }
  if(!DFS(0, 0)) {
    cout << 1;
    return 0;
  }
  cout << 2;
  return 0;
}
