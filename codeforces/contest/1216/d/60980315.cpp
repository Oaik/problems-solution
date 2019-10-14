#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
const int M = 2e5 + 9;

int arr[M];

int main() {
  fastIO;
  int k, c, ya = -1;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> c;
    arr[i] = c;
  }

  ll ans = 0;
  sort(arr, arr + k);
  for (int i = 0; i < k-1; ++i) {
    int diff = arr[k-1] - arr[i];
    if(ya == -1)
      ya = diff;
    else
      ya = __gcd(ya, diff);
  }
  for (int i = 0; i < k-1; ++i) {
    int diff = arr[k-1] - arr[i];
    ans += diff / ya;
  }

  cout << ans;
  cout << ' ';
  cout << ya;
  return 0;
}
