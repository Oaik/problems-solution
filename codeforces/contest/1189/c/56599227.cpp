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

int arr[N];
ll pre[N];

int main() {
  debug();
  int n, q, l, r;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
  for (int i = 1; i <= n; ++i)
    pre[i] += pre[i - 1] + arr[i];
  cin >> q;
  while(q--) {
    cin >> l >> r;
    cout << (pre[r] - pre[l - 1]) / 10 << '\n';
  }
  return 0;
}
