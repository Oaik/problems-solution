#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)    ((v).begin()),((v).end())
#define clr(a,b)  memset(a,b,sizeof(a))
const double EPS = 1e-8, pi = acos(-1);
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  // freopen("output.in", "wt", stdout);
#endif
}

int const N = 2e5 + 9, OO = 1e9;

bool arr[101];

int main() {
  cout << fixed << setprecision(12);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  debug();
  int n, a, mn = 101;
  ll sum = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    sum += a;
    arr[a] = 1;
    mn = min(mn, a);
  }
  ll dif = 0, cur = sum, ans = sum;
  for (int i = 100; i >= 4; --i) {
    if(!arr[i])
      continue;
    for (int j = 1; j <= i; ++j) {
      if(i % j != 0)
        continue;
      cur = sum;
      dif = (i / j) + (mn * j);
      cur -= ((i) + (mn));
      cur += dif;
      ans = min(cur, ans);
    }
  }
  cout << ans;
  return 0;
}
