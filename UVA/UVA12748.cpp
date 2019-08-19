#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-6, PI = acos(-1);
const int N = 1e2 + 9, OO = 1e9;

struct circle {
  int x, y, r;
  circle() {
    this->x = 0;
    this->y = 0;
    this->r = 0;
  }
  circle(int _r, int _x, int _y) {
    this->x = _x;
    this->y = _y;
    this->r = _r;
  }
};

circle arr[N];

int main() {
  fastIO;
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case " << i << ':' << '\n';
    int n, m;
    cin >> n >> m;
    int r, x, y;
    for (int j = 0; j < n; ++j) {
      cin >> x >> y >> r;
      arr[j] = circle(r, x, y);
    }
    ll dist;
    for (int j = 0; j < m; ++j) {
      cin >> x >> y;
      bool can = 0;
      for (int k = 0; k < n; ++k) {
        dist = (ll)(x - arr[k].x) * (x - arr[k].x) + (ll)(y - arr[k].y) * (y - arr[k].y);
        if(dist <= (ll)arr[k].r *arr[k].r) {
          can = 1;
          break;
        }
      }
      if(can)
        cout << "Yes\n";
      else
        cout << "No\n";
    }
  }
  return 0;
}

