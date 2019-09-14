#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(10), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
double const EPS = 1e-8, PI = acos(-1);
const int N = 25 + 9, OO = 1e9;

int f[N], d[N],t[N], mem[N][1000][100], n, h;
int DP(int time, int x, int factor) {
  if(time <= 0)
    return 0;
  int& ret = mem[x][time][factor];
  if(~ret)
    return ret;
  ret = 0;
  ret = DP(time - 5, x, factor + 1) + max(0, f[x] - (factor * d[x]));
  if(x < n)
    ret = max(ret, DP(time - (5*t[x]), x + 1, 0));
  return ret;
}

int path[N];

void printPath(int time, int x, int factor) {
  if(time <= 0)
    return;
  int c1 = OO, c2 = OO, ans = DP(time, x, factor);
  c1 = DP(time - 5, x, factor + 1) + max(0, f[x] - (factor * d[x]));
  if(x < n)
    c2 = DP(time - (5*t[x]), x + 1, 0);
  if(c1 == ans) {
    path[x] += 5;
    return printPath(time - 5, x, factor + 1);
  } else
    return printPath(time - (5*t[x]), x + 1, 0);
}

int main() {
  fastIO;
//  read;
//  write;
  bool en = 0;
  while(cin >> n, n) {
    cin >> h;
    if(en)
      cout << '\n';
    h *= 60;
    for (int i = 0; i < n; ++i)
      cin >> f[i];
    for (int i = 0; i < n; ++i)
      cin >> d[i];
    --n;
    for (int i = 0; i < n; ++i)
      cin >> t[i];
    clr(mem, -1);
    clr(path, 0);
    DP(h, 0, 0);
    printPath(h, 0, 0);
    ++n;
    cout << path[0];
    for (int i = 1; i < n; ++i) {
      cout << ',' << ' ' << path[i];
    }
    cout << '\n';
    cout << "Number of fish expected: " << DP(h, 0, 0) << '\n';
    en = 1;
  }
  return 0;
}

