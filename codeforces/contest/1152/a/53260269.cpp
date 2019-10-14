#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  // freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int const N = 3e5 + 9, OO = 1e9;

int main() {
  debug();
  int n, m,a, odd = 0, even = 0;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if(a & 1)
      ++odd;
    else
      ++even;
  }
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    cin >> a;
    if(a & 1) {
      if(even) {
        ++ans;
        --even;
      }
    } else {
      if(odd) {
        ++ans;
        --odd;
      }
    }
    if(!even && !odd)
      break;
  }
  cout << ans;
}
