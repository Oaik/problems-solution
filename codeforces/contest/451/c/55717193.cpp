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
const int N = 1e5 + 9, OO = 1e9;

bool printIt(bool can) {
  if (can)
    cout << "yes\n";
  return can;
}
ll rem;
bool calc(ll a, ll b, ll c) {
  ll mx = max(a, max(b, c));
  rem -= mx - a;
  rem -= mx - b;
  rem -= mx - c;
  if (rem >= 0 && rem % 3 == 0)
    return 1;
  return 0;
}

int main() {
  debug();
  int t;
  cin >> t;
  while (t--) {
    ll n, k, d1, d2;
    bool can = 0;
    cin >> n >> k >> d1 >> d2;
    rem = n - k;
    ll try1 = -d1 + k + d2, try2 = -d1 + k - d2, try3 = d1 + k - d2, try4 = d1 + k + d2;
    ll a, b, c;
    if (try1 >= 0 && try1 % 3 == 0) {
      b = try1 / 3;
      a = d1 + b;
      c = b - d2;
      if (a + b + c == k && a >= 0 && b >= 0 && c >= 0) {
        rem = n - k;
        if(calc(a, b, c))
          can = 1;
      }
    }
    if(try2 >= 0 && try2 % 3 == 0) {
      b = try2 / 3;
      a = d1 + b;
      c = d2 + b;
      if(a + b + c == k && a >= 0 && b >= 0 && c >= 0) {
        rem = n - k;
        if(calc(a, b, c))
          can = 1;
      }
    }
    if(try3 >= 0 && try3 % 3 == 0) {
      b = try3 / 3;
      a = b - d1;
      c = d2 + b;
      if(a + b + c == k && a >= 0 && b >= 0 && c >= 0) {
        rem = n - k;
        if(calc(a, b, c))
          can = 1;
      }
    }
    if(try4 >= 0 && try4 % 3 == 0) {
      b = try4 / 3;
      a = b - d1;
      c = b - d2;
      if(a + b + c == k && a >= 0 && b >= 0 && c >= 0) {
        rem = n - k;
        if(calc(a, b, c))
          can = 1;
      }
    }
    if (printIt(can))
      continue;
    cout << "no\n";
  }
  return 0;
}
