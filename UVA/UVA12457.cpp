#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "r", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(2), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 2e3 + 9, M = 2e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

int n, total;
double p;
double mem[59][59];

double solve(int idx, int wins) {
  if(idx == total) {
    if(wins >= n)
      return 1.0;
    return 0;
  }
  double& ret = mem[idx][wins];
  if(ret == ret)
    return ret;
  ret = 0;
  ret += solve(idx + 1, wins + 1) * p;
  ret += solve(idx + 1, wins) * (1 - p);
  return ret;
}

int main() {
  fastIO;
//  read("input.in");
//  write("input.in");
  int t;
  cin >> t;
  while(t--) {
    clr(mem, -1);
    cin >> n >> p;
    total = 2*n - 1;
    cout << solve(0, 0);
    cout << '\n';
  }
  return 0;
}

