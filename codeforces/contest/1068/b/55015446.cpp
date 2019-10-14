#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
const int N = 1e5 + 9, OO = 1e9 + 9;

set<int> st;

int main() {
  debug();
  ll a;
  cin >> a;
  for (ll i = 1; i * i <= a; ++i) {
    if(a % i == 0)
      st.insert(a/i), st.insert(i);
  }
  cout << st.size();
  return 0;
}
