#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 5e3 + 9, OO = 1e9 + 9;

int n, m, t;
vector<pair<int, int>> vec[N];
vector<int> ans;
int mem[N][N];

int DP(int x,int num) {
  if(num == 0) {
    if(x == n)
      return 0;
    return OO;
  }
  int& ret = mem[x][num];
  if(~ret)
    return ret;
  ret = OO;
  for(auto it: vec[x])
    ret = min(ret, DP(it.first, num - 1) + it.second);
  return ret;
}

void printPath(int x, int num) {
  if(num == 0) {
    if(x == n)
      ans.push_back(n);
    return;
  }
  int C = DP(x, num);
  int ret = OO;
  for(auto it: vec[x]) {
    ret = min(ret, DP(it.first, num - 1) + it.second);
    if(C == ret) {
      ans.push_back(it.first);
      printPath(it.first, num - 1);
      return;
    }
  }
}

int main() {
  fastIO;
  cin >> n >> m >> t;
  int u, v, c, l = 0;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> c;
    vec[u].push_back({v, c});
  }
  clr(mem, -1);
  for (int i = m; i >= 0; --i) {
    if(DP(1, i) <= t) {
      l = i;
      break;
    }
  }
//  cerr << l << endl;
  ans.push_back(1);
  printPath(1,l);
  ans.pop_back();
  cout << l + 1 << endl;
  for(int it: ans)
    cout << it << ' ';
  return 0;
}
