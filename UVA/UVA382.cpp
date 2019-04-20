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

int main() {
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  debug();
  ll n;
  cout << "PERFECTION OUTPUT\n";
  while(cin >> n, n) {
    cout << setw(5) << n;
    if(n == 1) {
      cout << "  DEFICIENT\n";
      continue;
    }
    ll sum = 1;
    for (ll i = 2; i * i < n; ++i) {
      if(n % i == 0) {
        sum += i + (n/ i);
      }
    }
    if(sum == n)
      cout << "  PERFECT";
    else if(sum > n)
      cout << "  ABUNDANT";
    else
      cout << "  DEFICIENT";
    cout << '\n';
  }
  cout << "END OF OUTPUT\n";
  return 0;
}

