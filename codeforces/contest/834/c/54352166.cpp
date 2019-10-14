#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
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
const int N = 2e5 + 9, OO = 2e9 + 9;

int main() {
  debug();
  int t;
  ll a, b, c;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    c = a * b;
    c = ceil(cbrt(c));
    if (c * c * c == (a * b) && a % c == 0 && b % c == 0) {
      cout << "YES\n";
    } else
      cout << "NO\n";
  }
}
