#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9;

int main() {
  fastIO;
  int n,
  x1, y1, x2, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;
  vector<pair<ll, ll> > dist;
  ll mxDist = 0, mxDist2 = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    ll one = (ll) (x - x1) * (x - x1) + (ll) (y - y1) * (y - y1);
    ll two = (ll) (x - x2) * (x - x2) + (ll) (y - y2) * (y - y2);
    dist.push_back({one, two});
    mxDist = max(mxDist, two);
    mxDist2 = max(mxDist2, one);
  }
  ll result = 2e18;
  for (auto i : dist) {
    ll r1 = i.first;
    ll r2 = 0;
    for (auto j : dist) {
      if (j.first > r1)
        r2 = max(r2, j.second);
    }
    result = min(result, r1 + r2);
  }
  result = min(result, mxDist);

  for (auto i : dist) {
    ll r1 = 0;
    ll r2 = i.second;
    for (auto j : dist) {
      if (j.second > r2)
        r1 = max(r1, j.first);
    }
    result = min(result, r1 + r2);
  }
  result = min(result, mxDist2);

  cout << result << '\n';
  return 0;
}
