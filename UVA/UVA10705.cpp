#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "r", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e4 + 9, M = 2e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

int main() {
//  read("input.in");
//  write("output.in");
  int t;
  cin >> t;
  while(t--) {
    ll n, k;
    string str, res;
    cin >> n >> str >> k;
    unsigned ll mx = 0, mn = 0;
    for (ll i = 0, j = n - 1; i < n; ++i, --j) {
      if(str[i] == 'p')
        mx += (1ll << j), res.push_back('1');
      else
        mn += (1ll << j), res.push_back('0');
    }
    unsigned ll x = abs(k);
    if((x > mx && k > 0) || (x > mn && k < 0)) {
      cout << "Impossible";
      cout << '\n';
      continue;
    }
    unsigned ll diff = mx - k;
    for (ll i = 0, j = n - 1; i < n; ++i, --j) {
      if(diff >= ((unsigned ll )1 << j)) {
        if(str[i] == 'p')
          res[i] = '0';
        else
          res[i] = '1';
        diff -= ((unsigned ll )1 << j);
      }
    }
    assert(diff == 0);
    cout << res << '\n';
  }
  return 0;
}

