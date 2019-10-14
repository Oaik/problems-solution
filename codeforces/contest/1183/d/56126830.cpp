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

int main() {
  debug();
  int q;
  cin >> q;
  while (q--) {
    priority_queue<int> qqq;
    int n, a;
    cin >> n;
    int cnt[n+1];
    clr(cnt, 0);
    while(!qqq.empty())
      qqq.pop();
    for (int i = 0; i < n; ++i) {
      cin >> a;
      ++cnt[a];
    }
    for (int i = 1; i <= n; ++i) {
      if(!cnt[i]) continue;
      qqq.push(cnt[i]);
    }
    ll total = 0, cur = qqq.top(), prv = INT_MAX;
    while(!qqq.empty()) {
      cur = qqq.top();
      qqq.pop();
      if(cur >= prv)
        cur = prv - 1;
      if(cur <= 0)
        break;
      total += cur;
      prv = cur;
    }
    cout << total << '\n';
  }
}
