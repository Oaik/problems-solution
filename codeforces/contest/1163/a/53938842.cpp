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
int const N = 1e3 + 9, M = 1e5 + 9, OO = 1e7;

bool vis[N];

int main() {
  debug();
  int n, m;
  cin >> n >> m;
  if(n == m) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= n; i += 2) {
    if(m > 0) {
      vis[i] = 1;
      --m;
    } else {
      break;
    }
  }
  for (int i = 2; i <= n; i += 2) {
    if(m > 0) {
      vis[i] = 1;
      --m;
    } else
      break;
  }
  bool f = 0;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if(vis[i]) {
      f = 0;
      continue;
    }
    if(!f)
      ++cnt;
    f = 1;
  }
  cout << cnt;
}
