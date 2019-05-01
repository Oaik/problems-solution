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
  cout << fixed << setprecision(6);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
int const N = 1e5 + 9, M = 1e5 + 9, OO = 1e9;

double arr[29];

int main() {
  debug();
  int n, r, idx = 1;
  while (cin >> n >> r, n || r) {
    cout << "Case " << idx << ":\n";
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    double B = 0, A, res;  // P(A,B) / P(B)
    for (int mask = 0; mask < (1 << n); ++mask) {  // P(B)
      if (__builtin_popcount(mask) == r) {
        res = 1;
        for (int i = 0; i < n; ++i) {
          if ((1 << i) & mask)
            res *= arr[i];
          else
            res *= (1 - arr[i]);
        }
        B += res;
      }
    }
    for (int j = 0; j < n; ++j) {  // P(A,B)
      A = 0;
      for (int mask = 0; mask < (1 << n); ++mask) {
        if (__builtin_popcount(mask) == r && ((1 << j) & mask)) {
          res = 1;
          for (int i = 0; i < n; ++i) {
            if ((1 << i) & mask)
              res *= arr[i];
            else
              res *= (1 - arr[i]);
          }
          A += res;
        }
      }
      cout << A / B << '\n';
    }
  ++idx;
  }
}

