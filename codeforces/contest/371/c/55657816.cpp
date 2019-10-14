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
const int N = 1e5 + 9, OO = 1e9;

int main() {
  debug();
  string str;
  cin >> str;
  ll reqa = count(all(str), 'B'), reqb = count(all(str), 'S'), reqc = count(all(str), 'C'), a, b, c, x, y, z;
  ll total = 0, cost, cnt = 0;
  cin >> a >> b >> c >> x >> y >> z >> cost;
  ll start = 0, end = 1e14, mid;
  while (start <= end) {
    mid = start + (end - start) / 2;
    total = (max((mid * reqa) - a, 0LL) * x) + (max(((mid * reqb)) - b, 0ll) * y) + ( max((mid * reqc) - c, 0LL) * z);
    if (total == cost) {
      cnt += mid;
      cout << cnt;
      return 0;
    } else if (total < cost) {
      start = mid + 1;
    } else
      end = mid - 1;
  }
  total = (max((start * reqa) - a, 0LL) * x) + (max(((start * reqb)) - b, 0ll) * y) + ( max((start * reqc) - c, 0LL) * z);
  if(total <= cost)
    cout << start;
  else
    cout << max(start - 1, 0LL);
  return 0;
}
