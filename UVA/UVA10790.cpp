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
  cout << fixed << setprecision(6);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
int const N = 2e5 + 9, M = 1e5 + 9, OO = 1e9;

int main() {
  debug();
  int a, b, idx = 0;
  while(cin >> a >> b, a || b) {
    ll total = 0;
    for (int i = 1; i <= a; ++i) {
      ll l = ((i-1) * (b - 1)) + ((a - i) * (1 - 1));
      ll r = ((i-1) * (b - b)) + ((a - i) * (b - 1));
      total += (b * (l + r))/2;
//      for (int j = 1; j <= b; ++j) { // 2, 4, 6, ...
//        total += (i - 1) * (b - j);
//        total += (a - i) * (j - 1);
//      }
    }
    cout << "Case " << ++idx << ':' << ' ' << total / 2 << endl;
  }
}

