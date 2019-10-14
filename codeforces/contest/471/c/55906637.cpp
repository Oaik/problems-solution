#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(12);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

double const EPS = 1e-8, PI = acos(-1);
const int N = 3e5 + 9, OO = 1e9;

int main() {
  debug();
  ll n;
  cin >> n;
  int i = 1, ans = 0;
  ll total = 2 * i + (i - 1);
  while(total <= n) {
    if((n + i) % 3 == 0)
      ++ans;
    ++i;
    total = 3 * (((ll)i * (ll)(i + 1))/2) - i;
  }
  cout << ans;
  return 0;
}
