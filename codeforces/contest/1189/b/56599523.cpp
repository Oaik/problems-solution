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
const int N = 1e5 + 9, OO = 2e9;
int arr[N], res[N];

int main() {
  debug();
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  sort(arr, arr + n);
  for (int i = 0; i < n-3; ++i)
    res[i] = arr[i];
  res[n-3] = arr[n-3];
  res[n-2] = arr[n-1];
  res[n-1] = arr[n-2];
  for (int i = 0; i < n; ++i) {
    int f = (i + 1) % n, s = (((i - 1) % n) + n) % n;
    if(res[f] + res[s] <= res[i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i)
    cout << res[i] << ' ';
  return 0;
}
