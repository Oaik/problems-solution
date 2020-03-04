#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "r", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 1e5 + 9, M = 2e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

vector<int> adj[N];
int mem[N][3];

int solve(int idx, int par, int state) {

  int& ret = mem[idx][state];
  if(~ret)
    return ret;
  ret = state;
  for(auto it: adj[idx]) {
    if(it == par) continue;
    if(state)
      ret += min(solve(it,idx, 1), solve(it,idx, 0));
    else
      ret += solve(it,idx, 1);
  }
  return ret;
}

int main() {
  fastIO;
//  read("input.in");
//  write("input.in");
  int n, u, v;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  clr(mem, -1);
  cout << min(solve(1, -1, 0), solve(1, -1, 1)) << '\n';
  return 0;
}

