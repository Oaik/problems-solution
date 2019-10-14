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

int const N = 2e5 + 9, OO = 1e9;

int main() {
  debug();
  int n, mn = 1e9, cnt =0, k = 0;
  string str, res = "ACTG";
  cin >> n >> str;
  for (int i = 0; i < n; ++i) {
    if(i + 4 > n)
      break;
    cnt = 0, k = 0;
    for (int j = i; j < i+4; ++j) {
      cnt += min(abs(str[j] - res[k]), 26 - abs(str[j] - res[k]));
      ++k;
    }
    mn = min(mn, cnt);
  }
  cout << mn;
  return 0;
}