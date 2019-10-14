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

int main() {
  debug();
  int a, b, c, diff;
  cin >> a >> b >> c;
  diff = abs(a - b);
  if(c == 0 && b == a) {
    cout << '0';
    return 0;
  }
  if(diff > c) {
    if(a > b) {
      cout << '+';
    } else if(b > a) {
      cout << '-';
    } else{
      cout << '0';
    }
  } else {
    cout << '?';
  }
  return 0;
}
