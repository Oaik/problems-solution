#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 5e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

int n, m, vid = 1;
unsigned ll mem[29][151];
int vis[29][151];

unsigned ll solve(int idx, int total) {
  if(idx == n) {
    if(total >= m)
      return 1;
    return 0;
  }
  if(vis[idx][total] == vid)
    return mem[idx][total];
  vis[idx][total] = vid;
  unsigned ll& ret = mem[idx][total];
  ret = 0;
  for (int i = 1; i < 7; ++i) {
    ret += solve(idx + 1, total + i);
  }
  return ret;
}

int main() {
  fastIO;
  while(cin >> n >> m, n || m) {
    unsigned ll nem = solve(0, 0);
    ++vid;
    if(nem == 0) {
      cout << '0' << '\n';
      continue;
    }
    unsigned ll dem = 1;
    for (int i = 0; i < n; ++i)
      dem *= 6;
    if(nem == dem) {
      cout << 1 << '\n';
      continue;
    }
    unsigned ll g = __gcd(nem, dem);
    nem /= g, dem /= g;
    cout << nem << '/' << dem << '\n';
  }
  return 0;
}

