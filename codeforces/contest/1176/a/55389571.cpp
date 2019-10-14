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
  cout << fixed << setprecision(4);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, OO = 1e9;

int main() {
  debug();
  int q;
  bool can = 0;
  ll n, steps = 0;
  cin >> q;
  while(q--) {
    can = 1, steps = 0;
    cin >> n;
    while(n != 1) {
      if(n % 5 == 0) {
        n /= 5;
        n *= 4;
        ++steps;
      } else if(n % 3 == 0) {
        n /= 3;
        n *= 2;
        ++steps;
      } else if(n % 2 == 0) {
        n /= 2;
        ++steps;
      } else {
        steps = -1;
        break;
      }
    }
    cout << steps << endl;
  }
  return 0;
}