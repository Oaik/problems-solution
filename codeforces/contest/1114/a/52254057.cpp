#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)    ((v).begin()),((v).end())
#define clr(a,b)  memset(a,b,sizeof(a))
const double EPS = 1e-8, pi = acos(-1);
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  // freopen("output.in", "wt", stdout);
#endif
}

int const N = 2e5 + 9, OO = 1e9;

int main() {
  cout << fixed << setprecision(12);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  debug();
  int a, b, c, x, y, z;
  cin >> x >> y >> z >> a >> b >> c;
  if(x > a) {
    cout << "NO";
    return 0;
  }
  a -= x;
  if(y > a + b) {
    cout << "NO";
    return 0;
  }
  c += a + b;
  c -= y;
  if(z > c) {
    cout << "NO";
    return 0;
  }
  cout << "YES";
  return 0;
}
