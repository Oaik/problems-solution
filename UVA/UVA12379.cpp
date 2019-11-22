#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "r", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 2e5 + 9, M = 1e2 + 9, OO = 1e8 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

vector<int> adj[N];
bool vis[N];
int mxLength, mxNode;

void DFS(int node, int length) {
  if(length > mxLength)
    mxLength = length, mxNode = node;
  vis[node] = 1;
  for(auto it: adj[node]) {
    if(vis[it]) continue;
    DFS(it, length + 1);
  }
}

int main() {
  fastIO;
//  read("input.in");
//  write("input.in");
  int t;
  cin >> t;
  while(t--) {
    int n, k, v, totalEdges = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> k;
      totalEdges += k;
      for (int j = 0; j < k; ++j) {
        cin >> v;
        adj[i].push_back(v);
      }
    }
    if(totalEdges)
      totalEdges /= 2;
    clr(vis, 0);
    mxLength = 0;
    DFS(1,0);

    clr(vis, 0);
    mxLength = 0;
    DFS(mxNode, 0);

    cout << mxLength + (totalEdges - mxLength) * 2 << '\n';

    for (int i = 1; i <= n; ++i)
      adj[i].clear();

  }
  return 0;
}

