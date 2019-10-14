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
const int N = 2e5 + 9, M = 2e7 + 1, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e16;

int main() {
  fastIO;
//  read("input.in");
//  write("output.in");
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    ll n, s1, v1, s2, v2;
    cin >> n >> s1 >> v1 >> s2 >> v2;
    ll total = 0;
    ll lllcm = s1 * s2 / __gcd(s1, s2);
    if(n >= lllcm + lllcm) {
      ll r = n / lllcm;
      --r;
      total = r * max(lllcm/s1 * v1,lllcm/s2 * v2);
      n -= r * lllcm;
    }
    if(s1 < s2)
      swap(s1, s2), swap(v1, v2);
    ll cnt = 0;
    for (ll i = 0; i * s1 <= n; ++i) {
      ll rem = (n - (i * s1)) / s2;
      cnt = max(cnt, i * v1 + rem * v2);
    }
    total += cnt;
    cout << "Case #" << i << ':' << ' ' << total << '\n';
  }
  return 0;
}

