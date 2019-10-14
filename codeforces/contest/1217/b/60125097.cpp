#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 1e6 + 9, OO = 1e9 + 9, MOD = 1e9 + 7;

vector<pair<ll, ll>> vec;
vector<ll> yaa;

int main() {
  fastIO
  int t;
  cin >> t;
  while(t--) {
    ll n, x, ans = OO, a, b;
    cin >> n >> x;
    vec.clear();
    ll mx = -1, mxA = -1, yaa = -1;
    pair<ll, ll > it;
    for (int i = 0; i < n; ++i) {
      cin >> a >> b;
      if(b >= a) {
        yaa = max(yaa, a);
        continue;
      }
      if(a - b > mx || (a - b >= mx && a > mxA)) {
        mx = (a - b);
        mxA = a;
        it = {a, b};
      }
      yaa = max(yaa, a);
    }
    ll start = 0, end = 1e9 + 9, mid, bestAns = OO;
    while(start <= end) {
      mid = start + (end - start) / 2;
      ll dmg = (it.first * mid);
      dmg -= (it.second * (mid));
      if(dmg + yaa >= x) {
        bestAns = min(bestAns, mid + 1);
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    ans = min(ans, bestAns);
    if(ans == OO)
      ans = -1;
    cout << ans << '\n';
  }
  return 0;
}
