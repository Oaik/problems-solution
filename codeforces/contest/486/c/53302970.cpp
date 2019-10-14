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
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int const N = 1e3 + 9, OO = 1e9;

int main() {
  debug();
  string s;
  int n, p, ans = 0;
  cin >> n >> p >> s;
  p--, n--;
  if (p > n / 2) {
    p = n - p;
//    reverse(all(s));
  }
  int l = -1, r = 0;

  for (int i = 0; i <= n / 2; i++) {
    if (s[i] != s[n - i]) {
      ans += min(abs(s[i] - s[n - i]), 26 - abs(s[i] - s[n - i]));
      if (l == -1)
        l = i, r = i;
      else
        r = i;
    }
  }
  if (l == -1) {
    cout << 0;
    return 0;
  }
  ans += min(abs(p - l), abs(p - r));
  ans += (r - l);
  cout << ans;
}
