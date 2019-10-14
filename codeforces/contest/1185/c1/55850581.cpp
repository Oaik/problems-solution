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
  cout << fixed << setprecision(12);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9;

int arr[209], ans[209], cum[209];

int main() {
  debug();
  int n, k, a;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
  for (int i = 1; i <= n; ++i)
    cum[i] += cum[i-1] + arr[i];
  int cnt = 0;
  ll total = 0;
  vector<int> vec;
  for (int i = 1; i <= n; ++i) {
    total = cum[i];
    if(cum[i] <= k) {
      ans[i] = 0;
    } else {
      vec.clear();
      cnt = 0;
      for (int j = 1; j < i; ++j)
        vec.push_back(arr[j]);
      sort(vec.begin(), vec.end(), greater<int>());
      for(auto it: vec) {
        total -= it;
        ++cnt;
        if(total <= k)
          break;
      }
      ans[i] = cnt;
    }
  }

  for (int i = 1; i <= n; ++i)
    cout << ans[i] << ' ';
  return 0;
}