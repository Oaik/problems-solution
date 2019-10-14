#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 5e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

vector<int> vec;

int main() {
  fastIO;
  int n, a;
  int g = -1;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    vec.push_back(a);
  }
  sort(all(vec));
  for (int i = 0; i < n-1; ++i) {
    int diff = vec[n-1] - vec[i];
    if(g == -1)
      g = diff;
    else
      g = __gcd(g, diff);
  }
  ll ans = 0;
  for (int i = 0; i < n-1; ++i) {
    int diff = vec[n-1] - vec[i];
    ans += diff / g;
  }
  cout << ans << ' ' << g;
  return 0;
}

