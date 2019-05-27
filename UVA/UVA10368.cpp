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
const int N = 1e5 + 9, OO = 1e9 + 9;

int main() {
  debug();
  int x, y;
  bool player = 0;
  while(cin >> x >> y, x && y) {
    player = 0;
    while(1) {
      if(x > y) swap(x, y);
      if(y % x == 0 || (y / x) >= 2) {
        if(!player)
          cout << "Stan wins\n";
        else
          cout << "Ollie wins\n";
        break;
      }
      player ^= 1;
      y -= x;
    }
  }
  return 0;
}

