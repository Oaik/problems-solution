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

map<int, int> mp;
set<int> st;

int main() {
  debug();
  int t = 9;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int sum = 0, ans = -1;
    for (int i = a; i <= b; ++i) {
      if (mp[i]) {
        if(mp[i] > sum) {
          sum = mp[i];
          ans = i;
        }
        continue;
      }
      int cur = 0;
      for (int j = 1; j * j <= i; ++j) {
        if (i % j == 0) {
          if(j != i/j)
            cur += 2;
          else
            ++cur;
        }
      }
      mp[i] = cur;
      if(cur > sum) {
        sum = cur;
        ans = i;
      }
    }
    cout << "Between " << a << " and " << b << ", " << ans << " has a maximum of " << sum << " divisors." << endl;
  }
  return 0;
}

