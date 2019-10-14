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
const int N = 2e5 + 9, OO = 1e9;

set<int> stA, stB;
vector<int> ans;

int main() {
  debug();
  int a, b, n;
  cin >> a >> b;
  for (ll i = 1; i * i <= a; ++i) {
    if(a % i == 0) {
      stA.insert(i);
      stA.insert(a/i);
    }
  }
  for (ll i = 1; i * i <= b; ++i) {
    if(b % i == 0) {
      stB.insert(i);
      stB.insert(b/i);
    }
  }
  for(auto it: stA) {
    if(stB.find(it) != stB.end())
      ans.push_back(it);
  }
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    int it = upper_bound(ans.begin(), ans.end(), b) - ans.begin();
    --it;
    int val = ans[it];
    if(val >= a)
      cout << val << '\n';
    else
      cout << -1 << '\n';
  }
  return 0;
}
