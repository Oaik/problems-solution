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
  int n;
  cin >> n;
  if(n <= 5) {
    cout << "-1\n";
  } else {
    cout << 1 << ' ' << 2 << '\n';
    cout << 2 << ' ' << 3 << '\n';
    cout << 2 << ' ' << 4 << '\n';
    for (int i = 5; i <= n; ++i)
      cout << 1 << ' ' << i << '\n';
  }
  for (int i = 2; i <= n; ++i)
    cout << 1 << ' ' << i << '\n';
}
