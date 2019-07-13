#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout << fixed << setprecision(0)
double const EPS = 1e-8, PI = acos(-1);

// Geomtry Problem
typedef complex<double> point;

#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )  // a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )  // a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

point reflect(point p, point p0, point p1) {
  point z = p - p0, w = p1 - p0;
  return conj(z / w) * w + p0;  // Refelect point p1 around p0p1
}

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

void ccw_testing() {
  point a(0, 0), b(10, 0);

  cout << ccw(a, b, point(20, 10)) << "\n";     // +1 => c is ccw for a-b
  cout << ccw(a, b, point(20, 0)) << "\n";      // +1 => Collinear after b

  cout << ccw(a, b, point(20, -10)) << "\n";    // -1 => c is cw for a-b
  cout << ccw(a, b, point(-20, 0)) << "\n";     // -1 => c is Collinear before a

  cout << ccw(a, b, a) << "\n";               // 0 => Collinear at a
  cout << ccw(a, b, b) << "\n";               // 0 => Collinear at b
  cout << ccw(a, b, (a + b) / 2.0) << "\n";       // 0 => Collinear between a-b

  // one can design ccw to behave little differently
  // e.g. consider Collinear at b = +1 and at a = -1
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

const int N = 3e5 + 9, OO = 1e9, v = 1e6;

vector<pair<point, point>> vp;
bool vis[N];

int main() {
  fastIO;
//  freopen("input.in", "rt", stdin);
  int t;
  cin >> t;
  while(t--) {
    vp.clear();
    int n, a, b, x, y;
    cin >> n;
    bool vis[n]= {};
    for (int i = 0; i < n; ++i) {
      cin >> a >> b >> x >> y;
      vp.push_back({point(a, b), point(x, y)});
    }
    int total = 0;
    for (int i = 0; i < (int)vp.size(); ++i) {
      int cnt = 0;
      for (int j = i+1; j < (int)vp.size(); ++j) {
        if(i == j)
          continue;
       if(intersect(vp[i].first,vp[i].second,vp[j].first,vp[j].second)) {
         if(!vis[j] && !vis[i])
           cnt += 4, vis[j] = 1, vis[j] = 1;
         else if(!vis[j] || !vis[i])
           cnt += 3, vis[j] = 1, vis[j] = 1;
       }
      }
      if(!cnt && !vis[i])
        cnt = 1;
      vis[i] = 1;
      total += cnt;
    }
    cout << total << '\n';
    if(t)
      cout << '\n';
  }
  return 0;
}

