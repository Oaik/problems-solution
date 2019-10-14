#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout << fixed << setprecision(3)
double const EPS = 1e-8, PI = acos(-1);
const int N = 3e5 + 9, OO = 1e9, v = 1e6;

vector<ll> vec;

int main() {
  fastIO;
//  freopen("input.in", "rt", stdin); // freopen("output.in", "wt", stdout);
  int n, m, a;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    vec.push_back(a);
  }
  for (int i = 1; i < n; ++i)
    vec[i] += vec[i-1];
  ll aa, cur = 0;
  for (int i = 0; i < m; ++i) {
    cin >> aa;
    cur += aa;
    int it = upper_bound(all(vec), cur) - vec.begin();
    if(it == n) {
      cout << n << '\n';
      cur = 0;
      continue;
    }
    cout << n - it << '\n';
  }
  return 0;
}
