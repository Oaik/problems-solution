#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, M = 1e6 + 1, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

bool can(int x, int cnt) {
  ll num = x;
  for (int i = 1; i < cnt; ++i) {
    if(inf / x < num) {
      return 0;
    }
    num *= x;
  }
  return 1;
}

set<ll> st;
vector<ll> vec;

void gen() {
  ll num;
  for (ll i = 2; i < M; ++i) {
    num = i * i * i;
    while(inf / i > num) {
      st.insert(num);
      num *= i;
    }
    st.insert(num);
  }
  for(ll it: st) {
    ll num = sqrt(it);
    num *= num;
    if(num == it)
      continue;
    vec.push_back(it);
  }
//  cerr << st.size() << " vs " << vec.size();
}

int main() {
  fastIO

  gen();
  int t;
  cin >> t;
  ll l, r;
  while(t--) {
    cin >> l >> r;
    ll numL = sqrt(l-1) + ( lower_bound(all(vec), l) - vec.begin() );
    ll numR = sqrt(r) + ( lower_bound(all(vec), r + 1) - vec.begin());
    cerr << numL << ' ' << numR << endl;
    cout << max(0ll, numR - numL) << endl;
  }
  return 0;
}
