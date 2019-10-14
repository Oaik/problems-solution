#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 5e4 + 9, M = 5e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

ll arr[N], pre[N], k, n;

bool can(ll sum) {
  ll ret = 0;
  for (int i = 1; i <= n; ++i) {
    ll start = i, end = n, mid, ans = 0;
    while(start <= end) {
      mid = start + (end - start) / 2;
      ll total = pre[mid] - pre[i - 1];
      if(total > sum) {
        end = mid -1;
      } else {
        ans = mid;
        start = mid + 1;
      }
    }
    if(ans)
      ret += (ll)ans - i + 1;
  }
  return ret >= k;
}

int main() {
  fastIO;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    pre[i] += pre[i-1] + arr[i];
  }
  ll start = 0, end = 1e15, mid, ans = -1;
  while(start <= end) {
    mid = start + (end - start) / 2;
    if(can(mid)) {
      ans = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  cout << ans;
  return 0;
}

