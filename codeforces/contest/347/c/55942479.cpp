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
const int N = 1e5 + 9, OO = 1e9;

string ans[] = {"Bob", "Alice"};
int main() {
  debug();
  int n, a, mx = 0, g;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    g = __gcd(g, a);
    mx = max(a, mx);
  }
  int rem = mx / g - n;
  if(!(rem & 1))
    cout << ans[0];
  else
    cout << ans[1];
}
