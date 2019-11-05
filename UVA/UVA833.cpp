#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "r", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 1e5 + 9, M = 2e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

typedef complex<double> point;
#define dp(a,b)                 ( (conj(a)*(b)).real() )  // a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )  // a*b sin(T), if zero -> parllel

bool intersectSegments(point a, point b, point c, point d, point & intersect) {
  double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
  if (fabs(d1) < EPS)
    return false;  // Parllel || identical

  double t1 = d2 / d1, t2 = d3 / d1;
  intersect = a + (b - a) * t1;

  if (t1 < -EPS || t1 > 1 + EPS || t2 < -EPS || t2 > 1 + EPS)
    return false;  //e.g ab is ray, cd is segment ... change to whatever
  return true;
}

struct seg {
  int x1, y1, x2, y2, signSlope;
} pts[N];

int main() {
  fastIO;
//  read("input.in");
//  write("input.in");
  int t;
  bool f = 0;
  cin >> t;
  while(t--) {
    if(f)
      cout << '\n';
    f = 1;
    int n, m, a, b, x, y;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a >> b >> x >> y;
      if(a > x) {
        swap(a, x);
        swap(b, y);
      }
      int slopeY = (y - b) >= 0,
          slopeX = (x - a) >= 0;
      bool slope = (slopeY == slopeX) ? 1: 0;
      pts[i] = {a, b, x, y, slope};
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
      cin >> a >> b;
      x = a, y = 0;
      while(1) {
        point inter(-OO, -OO), tt(-OO, -OO);
        int idx = 0;
        for (int j = 0; j < n; ++j) {
          point temp;
          if(intersectSegments(point(a, b), point(x, y), point(pts[j].x1, pts[j].y1), point(pts[j].x2, pts[j].y2), temp)) {
            if(temp.imag() > inter.imag()) {
              inter = temp;
              idx = j;
            }
          }
        }
        if(inter == tt)
          break;
        if(pts[idx].signSlope) {
          a = pts[idx].x1,
              b = pts[idx].y1 - 1;
        } else {
          a = pts[idx].x2,
              b = pts[idx].y2 - 1;
        }
        x = a;
      }
      cout << a << '\n';
    }
  }
  return 0;
}

