#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout << fixed << setprecision(2)
double const EPS = 1e-8, PI = acos(-1);

// Geomtry Problem
int dcmp(double x, double y) {
  if (fabs(x - y) <= EPS)
    return 0;
  else if (x > y)
    return 1;
  else
    return -1;
}
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

double getAngle_A_abc(double a, double b, double c) {
  double res = c * c + b * b - a * a;
  res /= (2 * c * b);
  return acos(res) * 180.0 / PI;
}

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

  if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
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

pair<double, point> findCircle(point a, point b, point c) {
  //create median, vector, its prependicular
  point m1 = (b + a) * 0.5, v1 = b - a, pv1 = point(v1.Y, -v1.X);
  point m2 = (b + c) * 0.5, v2 = b - c, pv2 = point(v2.Y, -v2.X);
  point end1 = m1 + pv1, end2 = m2 + pv2, center;
  intersectSegments(m1, end1, m2, end2, center);
  return make_pair(length(a - center), center);
}

vector<point> intersectLineCircle(point p0, point p1, point C, double r) {
  double a = dp(p1 - p0, p1 - p0), b = 2 * dp(p1 - p0, p0 - C), c = dp(p0-C, p0-C) - r * r;
  double f = b * b - 4 * a * c;

  vector<point> v;
  if (dcmp(f, 0) >= 0) {
    if (dcmp(f, 0) == 0)
      f = 0;
    double t1 = (-b + sqrt(f)) / (2 * a);
    double t2 = (-b - sqrt(f)) / (2 * a);
    v.push_back(p0 + t1 * (p1 - p0));
    if (dcmp(f, 0) != 0)
      v.push_back(p0 + t2 * (p1 - p0));
  }
  return v;
}

vector<point> intersectCircleCircle(point c1, double r1, point c2, double r2) {
  // Handle infinity case first: same center/radius and r > 0
  if (same(c1, c2) && dcmp(r1, r2) == 0 && dcmp(r1, 0) > 0)
    return vector<point>(3, c1);    // infinity 2 same circles (not points)

  // Compute 2 intersection case and handle 0, 1, 2 cases
  double ang1 = angle(c2 - c1), ang2 = getAngle_A_abc(r2, r1, length(c2 - c1));

  if (::isnan(ang2))  // if r1 or d = 0 => nan in getAngle_A_abc (/0)
    ang2 = 0;  // fix corruption

  vector<point> v(1, polar(r1, ang1 + ang2) + c1);

  // if point NOT on the 2 circles = no intersection
  if (dcmp(dp(v[0] - c1, v[0] - c1), r1 * r1) != 0 || dcmp(dp(v[0] - c2, v[0] - c2), r2 * r2) != 0)
    return vector<point>();

  v.push_back(polar(r1, ang1 - ang2) + c1);
  if (same(v[0], v[1]))  // if same, then 1 intersection only
    v.pop_back();
  return v;
}

const int N = 3e5 + 9, OO = 1e9, v = 1e6;

struct shape {
  double a, b, c, d;
  char fig;
} shape[N];

int main() {
  fastIO;
//  freopen("input.in", "rt", stdin);
  char fig;
  double a, b, c, d;
  int i = 1;
  while(cin >> fig, fig != '*') {
    shape[i].fig = fig;
    if(fig == 'c') {
      cin >> a >> b >> c;
      shape[i].a = a,shape[i].b = b,shape[i].c = c * c;
    } else {
      cin >> a >> b >> c >> d;
      shape[i].a = a,shape[i].b = b,shape[i].c = c, shape[i].d = d;
    }
    ++i;
  }
  int k = 1;
  bool can = 0;
  while(cin >> a >> b, dcmp(a, 9999.9) != 0 && dcmp(b, 9999.9) != 0) {
    can = 0;
    for (int j = 1; j < i; ++j) {
      if(shape[j].fig == 'c') {
        double dist = (shape[j].a - a) * (shape[j].a - a) + (shape[j].b - b) * (shape[j].b - b);
        if( dcmp(shape[j].c, dist) == 1) {
          can = 1;
          cout << "Point " << k << " is contained in figure " << j << '\n';
        }
      } else {
        if(a > shape[j].a && a < shape[j].c && b < shape[j].b && b > shape[j].d) {
          can = 1;
          cout << "Point " << k << " is contained in figure " << j << '\n';
        }
      }
    }
    if(!can)
      cout << "Point " << k << " is not contained in any figure" << '\n';
    ++k;
  }
  return 0;
}

