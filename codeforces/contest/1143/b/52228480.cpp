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

ll cal(int x) {
  ll res = 1;
  while(x) {
    res *= (x % 10);
    x /= 10;
  }
  return res;
}

int main() {
  cout << fixed << setprecision(12);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  debug();
  int n, num;
  cin >> n;
  ll ans = cal(n);
  string res = to_string(n), cur;
  int x = res.size();
  for (int i = 0; i < x; ++i) {
    cur = res;
    if(cur[i] == '0') {
      continue;
    }
    --cur[i];
    for (int j = i+1; j < x; ++j) {
      cur[j] = '9';
    }
    num = stoi(cur);
    ans = max(ans, cal(num));
  }
  cout << ans;
  return 0;
}
