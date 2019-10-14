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
const int N = 1e5 + 9, OO = 1e9;

ll arr[N];

int main() {
  debug();
  ll n, x;
  cin >> n >> x;
  --x;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  ll cnt = 0, idx;
  bool can = 1;
  ll mn = *min_element(arr, arr + n);
  for (int i = x; i >= 0; --i) {
    arr[i] -= mn;
    cnt += mn;
  }
  for (int i = n - 1; i > x; --i) {
    arr[i] -= mn;
    cnt += mn;
  }
  for (int i = x; i >= 0; --i) {
    if (!arr[i]) {
      can = 0;
      idx = i;
      break;
    }
    --arr[i];
    ++cnt;
  }
  for (int i = n - 1; i > x && can; --i) {
    if (!arr[i]) {
      can = 0;
      idx = i;
      break;
    }
    --arr[i];
    ++cnt;
  }
  arr[idx] = cnt;
  for (int i = 0; i < n; ++i)
    cout << arr[i] << ' ';
  return 0;
}
