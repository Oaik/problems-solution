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
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, OO = 1e9 + 9;

int main() {
  debug();
  ll n, m, k, l;
  cin >> n >> m >> k >> l;
//  if(m > n) {
//    cout << -1;
//    return 0;
//  }
  ll end = 1e18 / m, start = 1, mid, ans = -1;
  while(end >= start) {
    mid = start + (end - start) / 2;
    if(mid * m > n)
      end = mid - 1;
    else if(mid * m <= n && ( mid * m ) - k >= l)
      ans = mid, end = mid - 1;
    else
      start = mid + 1;
  }
  cout << ans;
  return 0;
}