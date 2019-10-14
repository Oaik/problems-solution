#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);   //freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-6, PI = acos(-1);
int const N = 1e5 + 9, M = 1e5 + 9, OO = 1e7;

int arr[N][11];

int main() {
  debug();
  ll n, a, mx = 0, mn = 1e6;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    ++arr[i][a];
  }
  for (int i = 1; i < n; ++i)
    for (int j = 1; j < 11; ++j)
      arr[i][j] += arr[i - 1][j];

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    mx = 0, mn = 1e6;
    for (int j = 1; j < 11; ++j) {
      if (!arr[i][j])
        continue;
      mx = max((ll)arr[i][j], mx), mn = min((ll)arr[i][j], mn);
    }
    int f = 0, s = 0;
    for (int j = 1; j < 11; ++j) {
      if (arr[i][j] == mx)
        ++f;
    }
    for (int j = 1; j < 11; ++j) {
      if (arr[i][j] == mn)
        ++s;
    }
    if ((s == 1 && f*mx == i) || (mx - mn == 1 && f == 1) || (mx - mn == 0 && (f == i+1 || f == 1)))
      ans.push_back(i + 1);
  }
  int res = *max_element(all(ans));
  cout << res;
}
