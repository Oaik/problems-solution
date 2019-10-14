#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout << fixed << setprecision(3)
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e6 + 9, OO = 1e9, v = 1e6;

vector<ll> vec, dd, tt;
ll ans[N];
bool taxi[N];

int main() {
  fastIO;
//  freopen("input.in", "rt", stdin); // freopen("output.in", "wt", stdout);
  ll n, m;
  cin >> n >> m;
  ll k = n + m, a;
  for (ll i = 0; i < k; ++i) {
    cin >> a;
    vec.push_back(a);
  }
  for (ll i = 0; i < k; ++i) {
    cin >> a;
    if(a)
      taxi[i] = 1, tt.push_back(vec[i]);
  }
  ll prv = -1;
  for (ll i = 0; i < k; ++i) {
    if(taxi[i]) {
      ++prv;
      continue;
    }
    ll it = upper_bound(all(tt), vec[i]) - tt.begin();
    if(it == m && prv != -1)
      ++ans[prv];
    else if((it != m) && prv == -1)
      ++ans[it];
    else {
      if(vec[i] - tt[prv] <= tt[it] - vec[i])
        ++ans[prv];
      else
        ++ans[it];
    }
  }
  for (ll i = 0; i < m; ++i)
    cout << ans[i] << ' ';
  return 0;
}
