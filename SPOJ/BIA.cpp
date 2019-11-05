#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "r", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 5e3 + 9, M = 2e3 + 9, OO = 1e9 + 7, MOD = 998244353;
const ll inf = 1e18;

vector<int> adj[N];
bool vis[N];

void DFS(int node) {
  if(vis[node])
    return;
  vis[node] = 1;
  for(int it: adj[node])
    if(!vis[it])
      DFS(it);
}

int main() {
  fastIO;
//  read("input.in");
//  write("input.in");
  int T = 10;
  while(T--) {
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
      adj[i].clear();
    for (int i = 0; i < m; ++i) {
      cin >> u >> v;
      adj[u].push_back(v);
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
      clr(vis, 0);
      vis[i] = 1; // delete current node so mark it as visited so no one will visit it
      DFS(1); // DFS from the server
      bool f = 1;
      for (int i = 1; i <= n; ++i) { // If all nodes are visited then this node is not cirtical
        if(!vis[i]) {
          f = 0;
          break;
        }
      }
      if(!f) // otherwise this node is cirtical
        ans.push_back(i);
    }
    n = ans.size();
    cout << n << '\n';
    for (int i = 0; i < n; ++i)
      cout << ans[i] << " \n"[i == n-1];
  }
  return 0;
}

