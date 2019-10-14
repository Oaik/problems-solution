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
  ll a, b, c, k;
  ll total = 0;
  cin >> a >> b >> c;
  k = min(a, b);
  total += (c * 2) + (k * 2), a -= k, b -= k;
  if(a && b) {
    k = min(a, b);
    total += (k * 2);
  } else if(b || a) {
    total++;
  }
  cout << total;
  return 0;
}