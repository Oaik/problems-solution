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

vector<pair<ll, int>> vec;
vector<int> ans;

int main() {
  cout << fixed << setprecision(12);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  debug();
  ll n, m, k, a, sum = 0;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    vec.push_back( { a, i + 1});
  }
  sort(all(vec), greater<>());
  for (int i = 0; i < m * k; ++i) {
    sum += vec[i].first;
    ans.push_back(vec[i].second);
  }
  cout << sum << endl;
  sort(all(ans));
  for (int i = 1; i < k; ++i) {
      cout << ans[i * m - 1] << " ";
  }
  return 0;
}
