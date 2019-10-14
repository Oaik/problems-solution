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
const int N = 1e5 + 9, M = 2e7 + 1, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e16;

int n, k;
ll mem[(1 << 12)][100][12];

ll solve(int mask, int r, ll kk) {
  if (r == n) {
    if (kk == k)
      return 1;
    return 0;
  }
  ll& ret = mem[mask][kk][k];
  if (~ret)
    return ret;
  ret = 0;
  for (int i = 0; i < n; ++i) {
    if (!(mask & (1 << i))) {
      int cnt = 0;
      for (int j = 0; j < i; ++j)
        if (!(mask & (1 << j)))
          ++cnt;
      ret += solve(mask | (1 << i), r + 1, kk + cnt);
    }
  }
  return ret;
}

void preprocs() {
  for (int i = 1; i < 13; ++i) {
    for (int j = 0; j < 100; ++j) {
      n = i, k = j;
      solve(0, 0, 0);
    }
  }
}

int main() {
  fastIO;
//  read("input.in");
//  write("output.in");
  int t;
  cin >> t;
  preprocs();
  clr(mem, -1);
  while (t--) {
    cin >> n >> k;
    if(k > 100) {
      cout << '0' << '\n';
      continue;
    }
    cout << solve(0, 0, 0) << '\n';
  }
  return 0;
}

