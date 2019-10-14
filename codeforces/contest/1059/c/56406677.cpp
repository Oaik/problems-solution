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

vector<pair<int, int>> vec;

int main() {
  debug();
  int n;
  cin >> n;
  int odds = n / 2 + (n & 1), evens = n / 2, ee = n / 2, ans = 2;
  int cur = 2, total = 0;
//  vec.push_back({cur, evens});
  while (evens) {
    cur *= 2;
    evens /= 2;
    if (evens <= 1)
      break;
    vec.push_back( { cur, evens });
    ans = cur;
  }
  for (int i = 0; i < odds; ++i)
    cout << 1 << ' ';
  if (n == 1)
    return 0;
  if (n == 3) {
    cout << 3;
    return 0;
  }
  for (int i = (int) vec.size() - 1; i >= 0; --i) {
    vec[i].second -= total;
    total = vec[i].second + total;
  }
  if (!vec.empty())
    --vec[vec.size() - 1].second;
  else
    total = 1;
  n -= (n & 1);
//  if(__gcd(n, ans) == ans) {
//    ans = n - (n & 1);
//  }
  int an = ans;
  for (int i = ans; i <= n; ++i) {
    if(__gcd(i, an) == an)
      ans = i;
  }
  vec.push_back( { ans, 1 });
  ee -= total;
  for (int i = 0; i < ee; ++i) {
    cout << 2 << ' ';
  }
  for (auto it : vec) {
    for (int i = 0; i < it.second; ++i)
      cout << it.first << ' ';
  }
  return 0;
}
