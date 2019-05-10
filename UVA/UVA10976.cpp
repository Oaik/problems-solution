#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-6, PI = acos(-1);
int const N = 1e5 + 9, M = 1e5 + 9, OO = 1e7;
vector<pair<int, int>> vec;
int main() {
  debug();
  int n;
  ll i = 0, f, s, g, ff, ss, gg;
  while (cin >> n) {
    vec.clear();
    i = n * 2;
    for (; i - n > 0; i -= 1) {
      f = i - n;
      s = i * n;
      g = __gcd(f, s);
      if (g == min(f, s)) {
        ff = (s / g) - n;
        ss = n * (s / g);
        gg = __gcd(ff, ss);
        vec.push_back( { s / g, ss / gg });
      }
    }
//    sort(all(vec));
    reverse(all(vec));
    cout << vec.size() << endl;
    for (auto it : vec) {
      cout << "1/" << n << " = " << 1 << "/" << it.first << " + " << 1 << "/" << it.second << endl;
    }
  }
}

