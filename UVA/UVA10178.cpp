#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "r", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(6), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 2e5 + 9, M = 3e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

map<char, char> par;
int res = 0;

char find(char x) {
  if(x == par[x]) return x;
  return par[x] = find(par[x]);
}

void join(char x, char y) {
  x = find(x), y = find(y);
  if(x == y) {
    ++res;
    return;
  }
  par[y] = x;
}

int main() {
  fastIO;
//  read("input.in");
//  write("input.in");
  int n, m;
  char c, cc;
  while(cin >> n >> m) {
    par.clear();
    res = 1;
    for (int i = 0; i < m; ++i) {
      cin >> c >> cc;
      if(par.find(c) == par.end())
        par[c] = c;
      if(par.find(cc) == par.end())
        par[cc] = cc;
      join(c, cc);
    }
    cout << res << '\n';
//    cout << 2 - (n - m) << '\n';
  }
  return 0;
}

