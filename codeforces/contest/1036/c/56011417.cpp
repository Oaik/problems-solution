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

vector<ll> vec;

void gen(int len = 0, int nonzeros = 0, ll cur = 0) {
  if(len == 18) {
    vec.push_back(cur);
    return;
  }
  gen(len + 1, nonzeros, cur * 10);
  if(nonzeros < 3) {
    for (int i = 1; i <= 9; ++i)
      gen(len+1, nonzeros + 1, cur * 10 + i);
  }
}

int main() {
  debug();
  gen();
  vec.push_back(1e18);
  int t;
  ll l, r;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    int ans = (upper_bound(all(vec), r) - vec.begin());
    ans -= lower_bound(all(vec), l) - vec.begin();
    cout << ans << '\n';
  }
}
