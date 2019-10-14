#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define rall(v) ((v).rbegin()),((v).rend())
#define read(v) freopen(v, "rt", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(2), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 5e5 + 9, M = 1e6 + 1, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e16;

bool arr[21][21];
ll mem[(1 << 20)];
int n, t;

ll solve(int mask, int r) {
  if(r == n) {
    if(mask == (1 << n) - 1)
      return 1;
    return 0;
  }
  ll& ret = mem[mask];
  if(~ret)
    return ret;
  ret = 0;
  for (int i = 0; i < n; ++i) {
    if(arr[r][i] && !(mask & (1 << i))) {
      ret += solve(mask | (1 << i), r + 1);
    }
  }
  return ret;
}

int main() {
  fastIO;
//  read("input.in");
//  write("output.in");
  cin >> t;
  while(t--) {
    cin >> n;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        cin >> arr[i][j];
    clr(mem, -1);
    ll ans = solve(0, 0);
    cout << ans;
    if(t)
      cout << '\n';
  }
  return 0;
}

