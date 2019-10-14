#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  //freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
int const N = 1e5 + 9, M = 1e5 + 9, OO = 1e9;

vector<ll> atLeast;

int main() {
  debug();
  ll n, m;
  cin >> n >> m;
  if(m == 0) {
    cout << n << " " << n;
    return 0;
  }
  ll cnt = 2, total = 1;
  for (int i = 2; i < n; ++i) {
    if(total >= m)
      break;
    ++cnt;
    total += i;
  }
  cout << max(0ll, n - (2 * m)) << " " << max(0ll, n - cnt);
}
