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
  int w, h, l;
  cin >> w >> h >> l;
  ll total = 0;
  for (int i = 1; i <= l; ++i) {
    total += 2 * (w - (4 *(i - 1)) ) + 2 * (h - (4 *(i - 1)) ) - 4;
  }
  cout << total;
  return 0;
}