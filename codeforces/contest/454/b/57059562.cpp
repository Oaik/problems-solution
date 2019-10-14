#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout << fixed << setprecision(0)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, OO = 1e9, v = 1e6;

int arr[N], sorted[N], app[N];

int main() {
  fastIO;
//  freopen("input.in", "rt", stdin);  // freopen("output.in", "wt", stdout);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    sorted[i] = arr[i];
  }
  sort(sorted , sorted + n );
  int pos,mn = OO, ans = OO;
  for (int i = 0; i < n; ++i)
    if(arr[i] < mn)
      mn = arr[i], pos = i;
  bool can1 = 1;
  for (int i = 1; i < n; ++i) {
    int j = (i + pos) % n, k = (((pos + i - 1) % n) + n ) % n;
    if(arr[j] < arr[k]) {
      can1 = 0;
      break;
    }
  }
  if(can1)
    ans = n - pos;
  can1 = 1, mn = OO;
  for (int i = 0; i < n; ++i)
    if(arr[i] <= mn)
      mn = arr[i], pos = i;
  for (int i = pos; i >= 0; --i) {
    if(arr[i] != mn)
      break;
    pos = i;
  }
  for (int i = 1; i < n; ++i) {
    int j = (i + pos) % n, k = (((pos + i - 1) % n) + n ) % n;
    if(arr[j] < arr[k]) {
      can1 = 0;
      break;
    }
  }
  if(ans == n)
    ans = 0;
  if(can1)
    ans = min(ans, n - pos);
  if(ans == n)
    ans = 0;
  if(ans == OO)
    ans = -1;
  cout << ans;
  return 0;
}
