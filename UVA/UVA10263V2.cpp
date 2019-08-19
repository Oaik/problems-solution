#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(4), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-6, PI = acos(-1);
const int N = 1e5 + 9, OO = 1e9;

int dcmp(double a, double b) {
  if (fabs(a - b) <= EPS)
    return 0;
  else if (a > b)
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

point reflect(point p, point p0, point p1) {
    point z = p-p0, w = p1-p0;
    return conj(z/w)*w + p0; // Refelect point p1 around p0p1
}


double getAngle_A_abc(double a, double b, double c) {
  double res = c * c + b * b - a*a;
  res /= (2 * c * b);
  return acos(res) * 180.0/PI;
}


bool isCollinear(point a, point b, point c) {
  return fabs( cp(b-a, c-a) ) < EPS;
}

//bool isPointOnRay(point p0, point p1, point p2) {
//    if(length(p2-p0) < EPS) return true;
//    return same( normalize(p1-p0), normalize(p2-p0) );
//}

bool isPointOnRay(point a, point b, point c) {  // not tested?
    if(!isCollinear(a, b, c))
      return false;
    return dcmp(dp(b-a, c-a), 0) == 1;
}

//bool isPointOnSegment(point a, point b, point c) {
//  return isPointOnRay(a, b, c) && isPointOnRay(b, a, c);
//}

bool isPointOnSegment(point a, point b, point c) {
  double acb = length(a-b), ac = length(a-c), cb = length(b-c);
  return dcmp(acb-(ac+cb), 0) == 0;
}

double distToLine( point p0, point p1, point p2 ) {
  return fabs(cp(p1-p0, p2-p0)/length(p0-p1)); // area = 0.5*b*h
}

//distance from point p2 to segment p0-p1
double distToSegment( point p0, point p1, point p2 ) {
  double d1, d2;
  point v1 = p1-p0, v2 = p2-p0;
  if( (d1 = dp(v1, v2) ) <= 0)  return length(p2-p0);
  if( (d2 = dp(v1, v1) ) <= d1) return length(p2-p1);
  double t = d1/d2;
  return length(p2 - (p0 + v1*t) );
}

//Edit by Me
// Distance from point p2 to segment p0-p1 and return the intersect point which is perpendicular
// from p0 to line segment p0-p1
double distToSegment( point p0, point p1, point p2, point &i ) {
  double d1, d2;
  point v1 = p1-p0, v2 = p2-p0;
  if( (d1 = dp(v1, v2) ) <= 0) {
    i = p0;
    return length(p2-p0);
  }
  if( (d2 = dp(v1, v1) ) <= d1) {
    i = p1;
    return length(p2-p1);
  }
  double t = d1/d2;
  i = (p0 + v1*t);
  return length(p2 - (p0 + v1*t) );
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
  point m1 = (b+a)*0.5, v1 = b-a, pv1 = point(v1.Y, -v1.X);
  point m2 = (b+c)*0.5, v2 = b-c, pv2 = point(-v2.Y, v2.X);
  point end1 = m1+pv1, end2 = m2+pv2, center;
  intersectSegments(m1, end1, m2, end2, center);
  return make_pair( length(a-center), center );
}

vector<point> intersectLineCircle(point p0, point p1, point C, double r) {
    double a = dp(p1-p0, p1-p0), b = 2*dp(p1-p0, p0-C),
           c = dp(p0-C, p0-C) - r*r;
    double f = b*b - 4*a*c;

    vector<point> v;
    if( dcmp(f, 0) >= 0) {
      if( dcmp(f, 0) == 0)  f = 0;
      double t1 =(-b + sqrt(f))/(2*a);
      double t2 =(-b - sqrt(f))/(2*a);
      v.push_back( p0 + t1*(p1-p0) );
      if( dcmp(f, 0) != 0)  v.push_back( p0 + t2*(p1-p0) );
    }
    return v;
}

vector<point> intersectCircleCircle(point c1, double r1, point c2, double r2) {
  // Handle infinity case first: same center/radius and r > 0
  if (same(c1, c2) && dcmp(r1, r2) == 0 && dcmp(r1, 0) > 0)
    return vector<point>(3, c1);    // infinity 2 same circles (not points)

  // Compute 2 intersection case and handle 0, 1, 2 cases
  double ang1 = angle(c2 - c1), ang2 = getAngle_A_abc(r2, r1, length(c2 - c1));

  if(::isnan(ang2)) // if r1 or d = 0 => nan in getAngle_A_abc (/0)
    ang2 = 0; // fix corruption

  vector<point> v(1, polar(r1, ang1 + ang2) + c1);

  // if point NOT on the 2 circles = no intersection
  if(dcmp(dp(v[0]-c1, v[0]-c1), r1*r1) != 0 ||
      dcmp(dp(v[0]-c2, v[0]-c2), r2*r2) != 0 )
    return vector<point>();

  v.push_back(polar(r1, ang1 - ang2) + c1);
  if(same(v[0], v[1]))  // if same, then 1 intersection only
    v.pop_back();
  return v;
}


vector<point> pts;
vector<pair<point, point>> segments;

int main() {
  fastIO;
//  read;
//  write;
  double x, y;
  while (cin >> x >> y) {
    point p(x, y);
    pts.clear();
    segments.clear();
    int n;
    cin >> n;
    ++n;
    double a, b;
    for (int i = 0; i < n; ++i) {
      cin >> a >> b;
      pts.push_back(point(a, b));
    }
    pts.push_back(pts[0]);
    double minDist = OO;
    for (int i = 0; i < n; ++i)
      segments.push_back( { pts[i], pts[i + 1] });
    double cur;
    point dum, ans;
    for (int i = 0; i < n; ++i) {
      cur = distToSegment( segments[i].first, segments[i].second, p, dum);
      if (dcmp(cur, minDist) <= 0) {
        minDist = cur;
        ans = dum;
      }
    }
    cout << ans.X << '\n' << ans.Y << endl;
  }
  return 0;
}

