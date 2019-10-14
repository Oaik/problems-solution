#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 5e3 + 9, M = 1e6 + 9, OO = 1e9 + 9, MOD = 1e9 + 7;

const int unVisited = 0, Visited = 1, Finished = 2;

vector<pair<int, int>> vec[N];
int mark[N];
bool ans[N];

void DFS(int u) {
  mark[u] = Visited;

  for(auto it: vec[u]) {
    if(mark[it.first] == unVisited) {
      DFS(it.first);
    } else if(mark[it.first] == Visited) {
      ans[it.second] = 1;
    }
  }

  mark[u] = Finished;
}

int main() {
  fastIO
  int n, m, u, v;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    --u, --v;
    vec[u].push_back({v, i});
  }
  for (int i = 0; i < n; ++i) {
    if(mark[i] == unVisited) {
      DFS(i);
    }
  }
  int res = 1;
  for (int i = 0; i < m; ++i) {
    if(ans[i]){
      res = 2;
      break;
    }
  }
  cout << res << '\n';
  for (int i = 0; i < m; ++i)
    cout << ans[i] + 1 << ' ';
  return 0;
}
