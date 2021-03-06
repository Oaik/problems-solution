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
  cout << fixed << setprecision(4);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
int const N = 2e5 + 9, OO = 1e9;

vector<int> vec;

int main() {
  debug();
  int n, m, a, total, g;
  while (cin >> n >> m, n || m) {
    vec.clear();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a;
      }
      vec.push_back(a);
    }
    total = 0;
    for(int ii: vec)
      total += ii;
    for(int ii: vec) {
      g = __gcd(total, ii);
      cout << ii / g << " / " << total / g << '\n';
    }
  }
}

