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
const int N = 1e5 + 9, OO = 1e9;

int arr[N], nt[N];
vector<pair<int, int>> vec;

int main() {
  debug();
  int n, m, l, r, mn = 1e9;
  cin >> n >> m;
//  for (int i = 1; i <= n; ++i)
//    arr[i] = 1;
  for (int i = 0; i < m; ++i) {
    cin >> l >> r;
    mn = min(mn, r - l + 1);
//    arr[l] = 0;
//    if (l == r)
//      nt[l] = 1;
//    vec.push_back( { l, r });
  }
//  for (int i = 2; i <= n; ++i) {
//    if (!nt[i] && arr[i] == 0 && arr[i - 1] == 0)
//      arr[i] = 1;
//    else if(!nt[i] && arr[i]) {
//      arr[i] += arr[i-1];
//    }
//  }
  cout << mn << '\n';
  for (int i = 0; i < n; ++i) {
    arr[i + 1] = (i % mn);
  }
  for (int i = 1; i <= n; ++i) {
    cout << arr[i] << ' ';
  }
  return 0;
}
