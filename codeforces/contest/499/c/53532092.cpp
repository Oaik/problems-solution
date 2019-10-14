#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  // freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(4);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
int const N = 1e6 + 9, M = 1e5 + 9, OO = 1e9;

int main() {
  debug();
  ll x1, x2, y1, y2, a, b, c, ans1, ans2, res;
  cin >> x1 >> y1;
  cin >> x2 >> y2;
  int n, cnt = 0;
  cin >> n;
  while(n--) {
    cin >> a >> b >> c;
    ans1 = a*x1 + b*y1 + c;
    ans2 = a*x2 + b*y2 + c;
    res = (ans1 < 0 && ans2 > 0) || (ans1 > 0 && ans2 < 0);
    if(res)
      ++cnt;
  }
  cout << cnt;
}
