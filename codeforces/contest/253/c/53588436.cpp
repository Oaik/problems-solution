#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
//#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);  freopen("output.txt", "wt", stdout);
//#endif
  cout << fixed << setprecision(4);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
int const N = 1e5 + 9, M = 1e5 + 9, OO = 1e9;

int arr[N], mem[109][N], dx[] ={0, 0, -1, 1} , dy[] = {1, -1, 0, 0};
int r1, c1, r2, c2, n;

//int dp(int x, int y) {
//  // invalid
//  if(x < 1 || x > n || y < 1)
//    return 1e9;
//  if(y > arr[x] + 1)
//    y = arr[x] + 1;
//  // base case
//  if(x == r2 && y == c2)
//    return 0;
//  int& ret = mem[x][y];
//  if(~ret)
//    return ret;
//  ret = 1e9;
//  for (int i = 0; i < 4; ++i) {
//    int nx = x + dx[i], ny = y + dy[i];
//    ret = min(ret, dp(nx, ny) + 1);
//  }
//  return ret;
//}

int BFS() {
  pair<int, int> cur;
  queue<pair<int, int>> q;
  q.push({r1, c1});
  int lvl = 0, sz;
  while(!q.empty()) {
    sz = q.size();
    while(sz--) {
      cur = q.front();
      q.pop();
      if(cur.first == r2 && cur.second == c2) {
        return lvl;
      }
      for (int i = 0; i < 4; ++i) {
        int nx = cur.first + dx[i], ny = cur.second + dy[i];
          if(nx < 1 || nx > n || ny < 1)
            continue;
          if(ny > arr[nx] + 1)
            ny = arr[nx] + 1;
          if(mem[nx][ny])
            continue;
          mem[nx][ny] = 1;
          q.push({nx, ny});
      }
    }
    ++lvl;
  }
}

int main() {
  debug();

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  cin >> r1 >> c1 >> r2 >> c2;
//  clr(mem, -1);
//  cout << dp(r1, c1);
  cout << BFS();
}
