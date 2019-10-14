#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
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
const int N = 2e5 + 9, OO = 2e9 + 9;

int arr[N];

int main() {
  debug();
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    arr[i] = abs(arr[i]);
  }
  sort(arr, arr+n);
  ll total = 0;
  for (int i = 0; i < n; ++i) {
    int l = i, r = n - 1, mid;
    while(l < r) {
      mid = l + (r - l + 1) / 2;
      if(arr[i] * 2 >= arr[mid])
        l = mid;
      else
        r = mid - 1;
    }
    total += (l - i);
  }
  cout << total;
}
