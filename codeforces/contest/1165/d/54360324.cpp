#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
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
const int N = 1e6 + 9, OO = 2e9 + 9;

vector<ll> vec;
set<ll> st;

int main() {
  debug();
  int t;
  bool can = 0;
  ll n, a, mnVal, mxVal;
  cin >> t;
  for (int k = 1; k <= t; ++k) {
    mnVal = 1e7, mxVal = 0;
    vec.clear();
    st.clear();
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a;
      mnVal = min(mnVal, a);
      mxVal = max(mxVal, a);
      vec.push_back(a);
    }
    sort(all(vec));
    ll num = mnVal * mxVal;
    for (ll j = 2; j * j <= num; ++j) {
      if (num % j == 0) {
        st.insert(num / j);
        st.insert(j);
      }
    }
    if (st.size() == vec.size()) {
      can = 1;
      int idx = 0;
      for (auto it : st) {
        if (vec[idx] != it) {
          cout << -1 << endl;
          can = 0;
          break;
        }
        ++idx;
      }
      if (can)
          cout << mnVal * mxVal << endl;
    } else
      cout << -1 << endl;
  }
}
