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
const int N = 2e3 + 9, OO = 1e9 + 9;

int arr[N];

int main() {
  debug();
  int n;
  cin >> n;
  n *= 2;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  ll sum1 = 0, sum2 = 0;
  n /= 2;
  for (int i = 0; i < n; ++i) {
    sum1 += arr[i];
  }
  for (int i = n; i < 2 * n; ++i) {
    sum2 += arr[i];
  }
  if(sum1 == sum2)
    cout << -1;
  else {
    n *= 2;
    for (int i = 0; i < n; ++i)
      cout << arr[i] << ' ';
  }
  return 0;
}