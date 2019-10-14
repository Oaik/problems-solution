#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define all(v)    ((v).begin()),((v).end())
#define clr(a,b)  memset(a,b,sizeof(a))
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);
// freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int const N = 1e9 + 9, OO = 1e9;


queue<ll> vec;
vector<ll> ans;
void preproc() {
  vec.push(4);
  vec.push(7);
  ans.push_back(4);
  ans.push_back(7);
  ll lvl = 10, q = vec.size(), sz;
  ll cur;
  while(--lvl) {
    q = vec.size();
    while(q--) {
      cur = vec.front();
      vec.pop();
      ans.push_back(stoll(to_string(cur) + '4'));
      ans.push_back(stoll(to_string(cur) + '7'));
      vec.push(stoll(to_string(cur) + '4'));
      vec.push(stoll(to_string(cur) + '7'));
    }
  }
}

int main() {
  debug();
  int l, r;
  preproc();
  cin >> l >> r;
  ll sum = 0;
  ll first = 0, idx;
  if(binary_search(all(ans), l)) {
    first = l;
    auto f = lower_bound(all(ans), l);
    idx = f - ans.begin();
  } else {
    auto f = upper_bound(all(ans), l);
    idx = f - ans.begin();
    first = ans[idx];
  }
  for (ll i = l; i <= r; ++i) {
    if(i > first) {
      first = ans[idx + 1];
      ++idx;
    }
    sum += first;
  }
  cout << sum;
//  for(auto it: ans)
//    cout << it << endl;
  return 0;
}
