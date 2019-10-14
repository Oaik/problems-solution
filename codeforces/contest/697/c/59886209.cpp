#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, M = 2e5 + 2, OO = 1e9 + 9, MOD = 1e9 + 7;

map<pair<ll, ll>, ll> mp;
multiset<pair<ll, ll>> st;

int main() {
  fastIO
  int q;
  cin >> q;
  int t;
  ll cnt = 0, u, v, c;
  for (int i = 0; i < q; ++i) {
    cin >> t >> u >> v;
    st.clear();
    if (t == 1) {
      cin >> c;
      while (u > 1) {
        st.insert( { u, u / 2 });
        u /= 2;
      }
      while (v > 1) {
        st.insert( { v, v / 2 });
        v /= 2;
      }
      pair<ll, ll> prv = { -1, -1 };
      for (pair<ll, ll> it : st) {
        if (it == prv)
          mp[ { it.first, it.second }] -= c, mp[ { it.second, it.first }] -= c;
        else
          mp[ { it.first, it.second }] += c, mp[ { it.second, it.first }] += c;
        prv = it;
      }
    } else {
      cnt = 0;
      while (u > 1) {
        st.insert( { u, u / 2 });
        u /= 2;
      }
      while (v > 1) {
        st.insert( { v, v / 2 });
        v /= 2;
      }
      pair<ll, ll> prv = { -1, -1 };
      for (pair<ll, ll> it : st) {
        if (it == prv)
          cnt -= mp[ { it.first, it.second }];
        else
          cnt += mp[ { it.first, it.second }];
        prv = it;
      }
      cout << cnt << '\n';
    }
  }
  return 0;
}
