#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(2), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9;

int main() {
  fastIO;
  ll n, a, g = -1;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if(g == -1)
      g = a;
    else
      g = __gcd(a, g);
  }
  set<int> st;
  for (ll i = 1; i * i <= g; ++i) {
    if(g % i == 0) {
      st.insert(i);
      st.insert(g / i);
    }
  }
  cout << st.size();
  return 0;
}
