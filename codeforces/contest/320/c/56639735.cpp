#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
//  freopen("input.in", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e2 + 9, OO = 1e9;
int mod = 1000000007;

ll power(ll x, ll y) {
  ll res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1)
      res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}

int main() {
  debug();
  string str;
  cin >> str;
  int n = str.size();
  ll a = power(2, n-1);
  ll b = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (str[i] == '1') {
      b += power(2, n - i - 1);
      b %= mod;
    }
  }
  ll ans = (a * b) % mod;
  cout << ans;
  return 0;
}
