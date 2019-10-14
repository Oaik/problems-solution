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
int const N = 2e5 + 9, M = 1e5 + 9, OO = 1e9;

int main() {
  debug();
  int n, a, x, b, y;
  cin >> n >> a >> x >> b >> y;
  while(1) {
    if(a == b) {
      cout << "YES\n";
      return 0;
    } 
    if(a == x || b == y)
      break;
    if(a == n)
      a = 1;
    else
      ++a;
    if(b == 1)
      b = n;
    else
      --b;
  }
  cout << "NO\n";

}