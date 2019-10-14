#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  // freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(4);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
int const N = 1e6 + 9, M = 1e5 + 9, OO = 1e9;

ll lvl[N], mem[N];
ll dp(int i) {
  if(i < 0)
    return 0;
  ll& ret = mem[i];
  if(~ret)
    return ret;
  ret = (lvl[i] > 0);
  ret += dp(i - lvl[i] - 1);
  return ret;
}

int main() {
  debug();
  int n, a, lps = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    lps = max(lps, a);
    cin >> lvl[a];
  }
  ll mx = 0;
  clr(mem, -1);
  for (int i = 0; i <= lps; ++i) {
    mx = max(mx, dp(i));
  }
  cout << n - mx;
}
