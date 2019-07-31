#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);odeforces.comodeforces.com
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e4 + 9, M = 1e2 + 9, OO = 1e9;

vector<vector<pair<int, int>>> adjList(N);
ll mxDist = 0;
int fNode;

void DFS(int x, int par, int depth = 0) {
  for(auto it: adjList[x]) {
    if(it.first != par)
      DFS(it.first, x, depth + it.second);
  }
  if(depth > mxDist) {
    mxDist = depth;
    fNode = x;
  }
}
int u, v, c;
int main() {
  fastIO;
//  read;
  string str;
  while(getline(cin, str)) {
    if(str.empty()) {
      mxDist = 0;
      DFS(u, -1, 0);
      mxDist = 0;
      DFS(fNode, -1, 0);
      cout << mxDist << endl;
      adjList = vector<vector<pair<int, int>>>(N);
      continue;
    }
    stringstream ss(str);
    int cnt = 3;
    while(cnt--) {
      if(cnt == 2)
        ss >> u;
      if(cnt == 1)
        ss >> v;
      if(cnt == 0)
        ss >> c;
    }
    adjList[u].push_back({v, c});
    adjList[v].push_back({u, c});
  }
  mxDist = 0;
  DFS(u, -1, 0);
  mxDist = 0;
  DFS(fNode, -1, 0);
  cout << mxDist << endl;
  return 0;
}

