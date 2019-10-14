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

ll arr[N];
vector<int> st, en;

int main() {
  debug();
  int n;
  ll m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    ll s, e;
    cin >> s >> e;
    st.push_back(s);
    en.push_back(e);
    arr[i + 1] = e - s;
  }
  for (int i = 1; i <= n; ++i)
    arr[i] += arr[i - 1];
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ll cnt = en[i], curH = m, req = i, prevPre = arr[i + 1];
    while (1) {
      if (curH <= 0)
        break;
      int it = lower_bound(all(st), cnt + curH) - st.begin() - 1;
      if (it <= req)
        break;
      if (cnt + curH < st[it])
        break;
      if (curH < (en[it] - en[req]) - (arr[it + 1] - prevPre))
        break;
      curH -= (en[it] - en[req]) - (arr[it + 1] - prevPre);
      req = it, cnt = en[it], prevPre = arr[it + 1];
    }
    ans = max(ans, cnt + curH - st[i]);
  }
  cout << ans;
}
