#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "r", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 2e5 + 9, M = 3e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

int arr[N], tail[N], saveLIS[N], saveSIS[N];

int main() {
  fastIO;
//  read("input.in");
//  write("input.in");
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      cin >> arr[i];
    clr(tail, 0);
    int length = 0;
    for (int i = 0; i < n; ++i) {
      int idx = lower_bound(tail, tail + length, arr[i]) - tail;
      tail[idx] = arr[i];
      if (idx == length)
        ++length;
      saveLIS[i] = idx + 1;
    }
    reverse(arr, arr + n);
    clr(tail, 0);
    length = 0;
    for (int i = 0; i < n; ++i) {
      int idx = lower_bound(tail, tail + length, arr[i]) - tail;
      tail[idx] = arr[i];
      if (idx == length)
        ++length;
      saveSIS[i] = idx + 1;
    }
    reverse(saveSIS, saveSIS + n);
    int ans = 0;
    for (int i = 0; i < n; ++i)
      ans = max(ans, min(saveSIS[i], saveLIS[i]) * 2 - 1 );
    cout << ans << '\n';
  }
  return 0;
}

