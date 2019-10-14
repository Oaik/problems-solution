#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9;

ll arr[N];

int main() {
  fastIO;
  int n;
  ll k;
  cin >> n >> k;
  int mid = n / 2;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  sort(arr, arr + n);
  ll ans = arr[mid];
  for (int i = mid; i < n; ++i) {
    ll mn = (arr[i+1] - arr[i]) * (ll)(i - mid + 1);
    if(mn > k ) {
      ans += (k / (i - mid + 1));
      k = 0;
    } else {
      ans += arr[i+1] - arr[i];
      k -= mn;
    }
  }
  if (k) {
    int cnt = n - mid;
    k /= cnt;
  }
  cout << ans + k;
  return 0;
}
