#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 3e5 + 9, OO = 1e9;

typedef complex<double> point;

#define X real()
#define Y imag()
#define cp(a,b)                 ( (conj(a)*(b)).imag() )  // a*b sin(T), if zero -> parllel

struct seg{
  point a, b;
};
seg arr[101];
// Where is P2 relative to segment p0-p1?
// ccw = +1 => angle > 0 or collinear after p1
// cw = -1 => angle < 0 or collinear after p0
// Undefined = 0 => Collinar in range [a, b]. Be careful here
int ccw(point a, point b, point c) {
  point v1(b - a), v2(c - a);
  double t = cp(v1, v2);

  if (t > +EPS)
    return +1;
  if (t < -EPS)
    return -1;
  if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
    return -1;
  if (norm(v1) < norm(v2) - EPS)
    return +1;
  return 0;
}

bool intersect(point p1, point p2, point p3, point p4) {
  // special case handling if a segment is just a point
  bool x = (p1 == p2), y = (p3 == p4);
  if (x && y)
    return p1 == p3;
  if (x)
    return ccw(p3, p4, p1) == 0;
  if (y)
    return ccw(p1, p2, p3) == 0;

  return ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}

bool notIso[101];

int main() {
  fastIO;
//  read;
  int n;
  cin >> n;
  while(n--) {
    int m, a, b, c, d;
    point u, v;
    clr(notIso, 0);
    cin >> m;
    for (int i = 0; i < m; ++i) {
      cin >> a >> b >> c >> d;
      u = point(a, b), v = point(c, d);
      arr[i].a = u;
      arr[i].b = v;
    }
    for (int i = 0; i < m; ++i) {
      for (int j = i+1; j < m; ++j) {
        if(intersect(arr[i].a, arr[i].b, arr[j].a, arr[j].b)) {
          notIso[i] = 1, notIso[j] = 1;
        }
      }
    }
    int cnt = 0;
    for (int i = 0; i < m; ++i)
      cnt += (!notIso[i]);
    cout << cnt << '\n';
  }
}

