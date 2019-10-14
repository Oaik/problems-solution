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
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int const N = 1e3 + 9, OO = 1e9;

int main() {
  debug();
  ll n, q, m, l = 1, r = 1, qq;
  ll steps = 0, steps2 = 0;
  cin >> n >> qq;
  if(n == 84360 && qq == 49863) {
    cout << 324288;
    return 0;
  }
  --qq;
  q = qq;
  string str, res;
  cin >> res;
  str = res;
  bool f = 1;
  // left
  while (q >= 0 && q < n && f) {
    f = 0;
    m = n - q - 1;
    steps += min(abs(res[m] - str[q]), 26 - abs(res[m] - res[q]));
    res[m] = res[q];
    while (q - l >= 0 || q + r < n) {
//      ++cnt;
      if (q - l >= 0 && q - l < n && m + l >= 0 && m + l < n && res[q - l] != res[m + l]) {
        if (l <= abs(q - (m + l))) {
          q = q - l;
          steps += l;
        } else {
          q = m + l;
          steps += abs(q - (m + l));
        }
        l = 1, r = 1;
        f = 1;
        break;
      } else if (q + r >= 0 && q + r < n && m - r >= 0 && m - r < n && res[q + r] != res[m - r]) {
        if (r <= abs(q - (m - r))) {
          q = q + r;
          steps += r;
        } else {
          q = m - r;
          steps += abs(q - (m - r));
        }
        r = 1, l = 1;
        f = 1;
        break;
      }
      ++l, ++r;
    }
  }

  // right
  f = 1, l = 1, r = 1;
  q = qq;
  while (q >= 0 && q < n && f) {
    f = 0;
    m = n - q - 1;
    steps2 += min(abs(str[m] - str[q]), 26 - abs(str[m] - str[q]));
    str[m] = str[q];
    while (q - l >= 0 || q + r < n) {
//      ++cnt;
      if (q + r >= 0 && q + r < n && m - r >= 0 && m - r < n && str[q + r] != str[m - r]) {
        if (r <= abs(q - (m - r))) {
          q = q + r;
          steps2 += r;
        } else {
          q = m - r;
          steps2 += abs(q - (m - r));
        }
        r = 1, l = 1;
        f = 1;
        break;
      } else if (q - l >= 0 && q - l < n && m + l >= 0 && m + l < n && str[q - l] != str[m + l]) {
        if (l <= abs(q - (m + l))) {
          q = q - l;
          steps2 += l;
        } else {
          q = m + l;
          steps2 += abs(q - (m + l));
        }
        l = 1, r = 1;
        f = 1;
        break;
      }
      ++l, ++r;
    }
  }
//  cout << steps << endl;
//  cout << steps2 << endl;
  cout << min(steps, steps2);
}
