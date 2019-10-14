#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
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
const int N = 2e5 + 9, OO = 2e9 + 9;

ll arr[N], pre[N];
vector<pair<ll, ll>> vec;
vector<ll> ans;

int main() {
  debug();
  int n, a;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    vec.push_back({a, i + 1});
  }
  sort(all(vec));
  pre[0] = vec[0].first;
  for (int i = 1; i < n; ++i)
    pre[i] += vec[i].first + pre[i - 1];
  ll num;
  for (int i = 0; i < n; ++i) {
    if(i == n-1) {
      num = pre[n-1] - vec[i].first - vec[n-2].first;
      if(num == vec[n-2].first)
        ans.push_back(vec[i].second);
    } else {
      num = pre[n-1] - vec[i].first - vec[n-1].first;
      if(num == vec[n-1].first)
        ans.push_back(vec[i].second);
    }
  }
  cout << ans.size() << endl;
  for(int it: ans)
    cout << it << " ";
}
