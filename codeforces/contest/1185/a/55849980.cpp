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

int arr[3];

int main() {
  debug();
  ll d;
  cin >> arr[0] >> arr[1] >> arr[2] >> d;
  sort(arr, arr + 3);
  ll ans = 0;
  if (arr[1] - arr[0] < d) {
    ans += d - abs(arr[1] - arr[0]);
    arr[0] -= d - abs(arr[1] - arr[0]);
  }
  if (arr[2] - arr[1] < d) {
    ans += d - abs(arr[2] - arr[1]);
  }
  cout << ans;
  return 0;
}