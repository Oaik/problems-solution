#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout << fixed << setprecision(0)
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9, v = 1e6;

int arr[11][101], mem[11][101], n, m, t;
vector<int> vec;

int DP(int x, int y) {
  if (y == m)
    return arr[x][y];
  int& ret = mem[x][y];
  if (~ret)
    return ret;
  ret = OO;
  int c1 = OO, c2 = OO, c3 = OO, finX = (x - 1 == 0) ? n : x - 1, lasX = (x == n) ? 1 : x + 1;
  c1 = DP(finX, y + 1) + arr[x][y];
  c2 = DP(x, y + 1) + arr[x][y];
  c3 = DP(lasX, y + 1) + arr[x][y];
  return ret = min(c1, min(c2, c3));
}

void printPath(int x, int y) {
  if (y == m) {
    vec.push_back(x);
    return;
  }
  int c1 = OO, c2 = OO, c3 = OO, ans = DP(x, y), src = OO, finX = (x - 1) == 0 ? n : x - 1, lasX = (x == n) ? 1 : x + 1, cho = -1;
  c1 = DP(finX, y + 1) + arr[x][y];
  c2 = DP(x, y + 1) + arr[x][y];
  c3 = DP(lasX, y + 1) + arr[x][y];
  if (ans == c1 && finX < src)
    src = finX, cho = 1;
  if (ans == c2 && x < src)
    src = x, cho = 2;
  if (ans == c3 && lasX < src)
    src = lasX, cho = 3;
  vec.push_back(x);
  if (cho == 1)
    printPath(finX, y + 1);
  else if (cho == 2)
    printPath(x, y + 1);
  else
    printPath(lasX, y + 1);
}

int main() {
  fastIO;
//  freopen("input.in", "rt", stdin);  // freopen("output.in", "wt", stdout);
  while (cin >> n >> m) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        cin >> arr[i][j];
    vec.clear();
    clr(mem, -1);
    int mn = OO, idx = -1;
    for (int i = 1; i <= n; ++i)
      if (DP(i, 1) < mn)
        mn = DP(i, 1), idx = i;
    printPath(idx, 1);
    cout << vec[0];
    for (int i = 1; i < (int) vec.size(); ++i)
      cout << ' ' << vec[i];
    cout << '\n';
    cout << mn << '\n';
  }
  return 0;
}

