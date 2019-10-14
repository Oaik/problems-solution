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
const int N = 3e5 + 9, OO = 1e9;

int main() {
  debug();
  int n;
  cin >> n;
  int ans = 1;
  for (int i = 1; i < n; ++i) {
    ans += (i * 4);
  }
  cout << ans;
  return 0;
}