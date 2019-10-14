#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 3e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

vector<pair<int, int>> adj[N];
ll vals[N], ans;

ll DFS1(int x, int par) {
  for(auto it: adj[x]) {
    if(it.first == par)
      continue;
    vals[it.first] += it.second;
    vals[it.first] += it.second;
    vals[x] += DFS1(it.first, x);
  }
  return vals[x];
}

ll DFS2(int x, int par) {
  ll mx = 0;
  for(auto it: adj[x]) {
    if(it.first == par)
      continue;
    mx = max(mx, DFS2(it.first, x) + it.second);
  }
  return mx;
}

int main() {
  fastIO;
  int n, u, v, c;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    cin >> u >> v >> c;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }
  DFS1(1, 0);
  cerr << vals[1];
//  ans = vals[1];
  vals[1] -= DFS2(1, 0);
  cout << vals[1];
  return 0;
}
