#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  //freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
int const N = 1e5 + 9, M = 1e5 + 9, OO = 1e9;

ll arr[59];

int main() {
  debug();
  ll n, m, h, a, b, c;
  cin >> n >> h >> m;
  for (int i = 1; i <= n; ++i) {
    arr[i] = h;
  }
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    for (int j = a; j <= b; ++j) {
        arr[j] = min(arr[j], c);
    }
  }
  ll total = 0, cnt = n;
//  sort(arr, arr+n);
  for (int i = 1; i <= n && cnt; ++i) {
    total += arr[i] * arr[i];
  }
  cout << total;
}
