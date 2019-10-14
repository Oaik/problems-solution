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
const int N = 3e5 + 9, OO = 1e9;

int arr[N], n, m;
bool can(int mx) {
  int prv = 0;
  for (int i = 0; i < n; ++i) {
    if(prv >= arr[i]) {
      if(prv - arr[i] > mx)
        return 0;
    } else {
      if(m - arr[i] + prv > mx)
        prv = arr[i];
    }
  }
  return 1;
}

int main() {
  debug();
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  int lo = 0, hi = m, mid, ans = 0;
  while(lo <= hi) {
    mid = lo + (hi - lo) / 2;
    if(can(mid)) {
      ans = mid;
      hi = mid - 1;
    } else
      lo = mid + 1;
  }
  cout << ans;
  return 0;
}
