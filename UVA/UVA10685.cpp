#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  //freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
int const N = 5e3 + 9, M = 1e5 + 9, OO = 1e9;

int mx = 0;
unordered_map<string, string> par;
unordered_map<string, int> sz;

string find(string str) {
  if (par[str] == str)
    return str;
  return par[str] = find(par[str]);
}

void join(string x, string y) {
  x = find(x), y = find(y);
  if (x != y) {
    if (sz[x] < sz[y])
      swap(x, y);
    par[y] = x;
    sz[x] += sz[y];
    mx = max(mx, sz[x]);
  }
}

int main() {
  debug();
  int r, c;
  char str1[31], str2[31];
  while (scanf("%d %d", &r, &c), (r || c)) {
    mx = 1;
    for (int i = 0; i < r; ++i) {
      scanf("%s", str1);
      par[str1] = str1;
      sz[str1] = 1;
    }
    for (int i = 0; i < c; ++i) {
      scanf("%s %s", str1, str2);
      join(str1, str2);
    }
    printf("%d\n", mx);
  }
}

