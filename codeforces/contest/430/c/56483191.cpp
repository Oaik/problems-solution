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

bool vis[N], cur[N], ans[N], hasChanged[N];
int par[N];
vector<vector<int>> vec(N);
queue<int> qq;
vector<int> out;

int main() {
  debug();
  int n;
  cin >> n;
  clr(vis, 0);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    vec[u].push_back(v);
    vec[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i)
    cin >> cur[i];
  for (int i = 1; i <= n; ++i)
    cin >> ans[i];
  qq.push(1);
  int tp, prevPar;
  while (!qq.empty()) {
    tp = qq.front();
    qq.pop();
    vis[tp] = 1;
    prevPar = par[par[tp]];
    if(hasChanged[prevPar]) {
      cur[tp] = !cur[tp];
      hasChanged[tp] = 1;
    }
    if (cur[tp] != ans[tp]) {
      hasChanged[tp] = !hasChanged[tp];
      out.push_back(tp);
    }
    for (int it : vec[tp]) {
      if (!vis[it]) {
        par[it] = tp;
        qq.push(it);
      }
    }
  }
  cout << out.size() << '\n';
  for (int it : out)
    cout << it << '\n';
  return 0;
}
