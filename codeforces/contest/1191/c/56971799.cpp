#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout << fixed << setprecision(0)
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e6 + 9, OO = 1e9, v = 1e6;

set<ll> st;

int main() {
  fastIO;
//  freopen("input.in", "rt", stdin); // freopen("output.in", "wt", stdout);
  ll n, m, k, prv = 0, a, killed = 0;
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i) {
    cin >> a;
    st.insert(a);
  }
  ll ans = 0;
  bool can = 0;
  while(!st.empty()) {
    ll pg = *st.begin() - killed - 1;
    pg /= k, can = 0;
    while(!st.empty() && pg == ((*st.begin() - prv - 1) / k)) {
      can = 1;
      ++killed;
      st.erase(st.begin());
    }
    if(can)
      ++ans;
    else
      break;
    prv = killed;
  }
  cout << ans;
  return 0;
}
