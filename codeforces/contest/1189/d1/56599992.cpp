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
const int N = 1e5 + 9, OO = 2e9;
int in[N], par[N];
bool vis[N];
int main() {
  debug();
  int n, u, v;
  cin >> n;
//  if(n == 2) {
//    cout << "YES\n";
//    return 0;
//  }
  --n;
  for (int i = 0; i < n; ++i) {
    cin >> u >> v;
    ++in[u],++in[v];
  }
  ++n;
  for (int i = 1; i <= n; ++i) {
    if(in[i] == 1)
      continue;
    if(in[i] == 2) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
