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
const int N = 3e5 + 99, OO = 1e9;

ll arr[N], cum[N], cnt[101];
priority_queue<int, vector<int>> qu;

int main() {
  debug();
  ll n, k;
  cin >> n >> k;
  for (ll i = 1; i <= n; ++i)
    cin >> arr[i];
  ll mx = 0, total, ans = 0;
  for (ll i = 1; i <= n; ++i) {
    cum[i] += cum[i - 1] + arr[i];
    total = cum[i], ans = 0;
    if (cum[i] > k) {
      for (int j = 100; j > 0 && total > k; --j) {
        if(!cnt[j]) continue;
        int req = min(((total - k) / j) + ((total - k) % j != 0), (ll)cnt[j]);
        total -= req * j, ans += req;
      }
    }
    ++cnt[arr[i]];
    cout << ans << " ";
  }
  return 0;
}
