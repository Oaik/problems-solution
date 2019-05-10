#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  //freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
int const N = 1e5 + 9, M = 1e5 + 9, OO = 1e9;

int main() {
  debug();
  ll n, m, cnt, tempM;
  while (cin >> n >> m) {  //  m divides !n
    set<pair<ll, ll>> st;
    if (m == 0) {
      cout << m << " does not divide " << n << '!' << endl;
      continue;
    }
    tempM = m;
    // prime factroize
    for (ll i = 2; i * i <= tempM; ++i) {
      cnt = 0;
      while (m % i == 0) {
        m /= i;
        ++cnt;
      }
      if (cnt)
        st.insert( { i, cnt });
    }
    if (m > 1)
      st.insert( { m, 1 });
    bool la2 = 0;
    ll cur = 0;
    for (auto it : st) {
      cur = it.first;
      while (it.second > 0) {
        if (cur > n) {
          cout << tempM << " does not divide " << n << '!' << endl;
          la2 = 1;
          break;
        }
        it.second -= n / cur;
        cur *= it.first;
      }
      if(la2)
        break;
    }
    if(!la2)
      cout << tempM << " divides " << n << '!' << endl;
  }
}

