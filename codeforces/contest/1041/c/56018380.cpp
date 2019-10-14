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

vector<pair<ll, ll>> vec;
vector<ll> vv;
ll ans[N];

int main() {
  debug();
  ll n, m, d;
  cin >> n >> m >> d;
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    vec.push_back({a, i});
    vv.push_back(a);
  }
  sort(all(vec));
  sort(all(vv));
  ll curDay = 1, mxDay = 1;
  for (int i = 0; i < n; ++i) {
    if(ans[vec[i].second])
      continue;
    ll val = vec[i].first;
    ans[vec[i].second] = curDay, mxDay = curDay;
    while(1) {
      ll it = lower_bound(all(vv), val + d + 1) - vv.begin();
      while(it != (int)vv.size() && ans[vec[it].second])
        ++it;
      if(it == (int)vv.size())
        break;
      ans[vec[it].second] = curDay;
      val = vec[it].first, mxDay = curDay;
    }
    ++curDay;
  }
  cout << mxDay << '\n';
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }
}