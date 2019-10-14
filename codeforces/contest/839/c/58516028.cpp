#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(12), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, OO = 1e9;
vector<vector<int>>vec(N);
vector<double> res;
void DFS(int x, int par = -1, int depth = 0, double per = 1) {
  bool en = 0;
  int sz = vec[x].size() - (par != -1);
  for(int it: vec[x]) {
    if(it != par) {
      DFS(it, x, depth + 1, per * (double)(1.0 / sz));
      en = 1;
    }
  }
  if(!en)
    res.push_back(depth * per);
}

int main() {
  fastIO;
//  read;
  int n;
  cin >> n;
  --n;
  int u, v;
  for (int i = 0; i < n; ++i) {
    cin >> u >> v;
    vec[u].push_back(v);
    vec[v].push_back(u);
  }
  DFS(1, -1, 0, 1.0);
  double ans = 0;
  for(double it: res)
    ans += it;
  cout << ans;
  return 0;
}
