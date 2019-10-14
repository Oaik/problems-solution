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
  cout << fixed << setprecision(4);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9;

vector<vector<int>> arr;
vector<int> ans, color;
bool vis[N];
int cnt1 = 0, cnt0 = 0;

void dfs(int u) {
  vis[u] = 1;
  for(auto it: arr[u]) {
    if(color[it] == -1) {
      color[it] = !color[u];
      if(color[it] == 1)
        ++cnt1;
      else
        ++cnt0;
      dfs(it);
    }
  }
}

int main() {
  debug();
  int t, n, m, u, v;
  cin >> t;
  while(t--) {
    cin >> n >> m;
    cnt1 = 0, cnt0 = 0;
    arr = vector<vector<int>>(n+1);
    clr(vis, 0);
    ans.clear();
    for (int i = 0; i < m; ++i) {
      cin >> u >> v;
      arr[u].push_back(v);
      arr[v].push_back(u);
    }
    color = vector<int>(n+1, -1);
    color[1] = 1;
    ++cnt1;
    dfs(1);
    if(cnt0 < cnt1) {
      cout << cnt0 << '\n';
      for (int i = 1; i <= n; ++i) {
        if(!color[i])
          cout << i << " ";
      }
    } else {
      cout << cnt1 << '\n';
      for (int i = 1; i <= n; ++i) {
        if(color[i] == 1)
          cout << i << " ";
      }
    }
    cout << '\n';
  }
  return 0;
}
