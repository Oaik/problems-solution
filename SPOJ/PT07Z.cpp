#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);odeforces.comodeforces.com
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 1e2 + 9, OO = 1e9;

vector<vector<int>> adjList;
int mxDist = 0, F;
void DFS(int x, int par, int depth = 0) {
  for(int it: adjList[x])
    if(it != par)
      DFS(it, x, depth + 1);
  if(depth > mxDist)
    mxDist = depth,F = x;
}

int main() {
  fastIO;
  int n, u, v;
  cin >> n;
  adjList = vector<vector<int>> (n);
  --n;
  for (int i = 0; i < n; ++i) {
    cin >> u >> v;
    --u, --v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  DFS(0, -1);
  mxDist = 0;
  DFS(F, -1);
  cout << mxDist;
  return 0;
}

