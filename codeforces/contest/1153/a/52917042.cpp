#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define all(v)    ((v).begin()),((v).end())
#define clr(a,b)  memset(a,b,sizeof(a))
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);
// freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int const N = 1e5 + 9, OO = 1e9;

int arr[N], dist[N];

int main() {
  debug();
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i] >> dist[i];
  }
  int t = 1e9, idx = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] >= k) {
      if (arr[i] - k < t) {
        t = arr[i] - k;
        idx = i;
      }
    } else {
      while (arr[i] < k) {
        arr[i] += dist[i];
      }
      if (arr[i] - k < t) {
        t = arr[i] - k;
        idx = i;
      }
    }
  }
  cout << idx + 1;
  return 0;
}