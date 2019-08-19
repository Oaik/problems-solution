#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(4), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, OO = 1e9;

struct point {
  double x, y;
  point() {
    x = y = 0.0;
  }
  point(double _x, double _y)
      : x(_x),
        y(_y) {
  }

  bool operator <(point other) const {
    if ((fabs(x - other.x) > EPS))
      return x < other.x;
    return y > other.y;
  }

  bool operator ==(point other) const {
    return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
  }
};
point dummy;

double dist(point p1, point p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y);
}

point rot(point p, double theta) {
  float rad = theta * PI / 180;
  return point(p.x * cos(rad) - p.y * sin(rad), p.x * cos(rad) + p.y * sin(rad));
}

/** --- LINES & VECTORS--- */

struct line {
  double a, b, c;
};

void pointsToLine(point p1, point p2, line &l) {
  if (fabs(p1.x - p2.x) < EPS) {
    l.a = 1.0, l.b = 0, l.c = -p1.x;
  } else {
    l.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1.0;
    l.c = -(double) (l.a * p1.x) - p1.y;
  }
}

bool areParrallel(line l1, line l2) {
  return fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS;
}

bool areEqu(line l1, line l2) {
  return areParrallel(l1, l2) && fabs(l1.c - l2.c) < EPS;
}

bool intersection(line l1, line l2, point &p) {
  if (areParrallel(l1, l2))
    return false;
  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  p.y = fabs(l1.b) > EPS ? -(l1.a * p.x + l1.c) : -(l2.a * p.x + l2.c);
  return true;
}

struct vec {
  double x, y;
  vec(double _x, double _y)
      : x(_x),
        y(_y) {
  }
};

vec toVec(point a, point b) {
  return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s) {
  return vec(v.x * s, v.y * s);
}

point translate(point p, vec v) {
  return point(p.x + v.x, p.y + v.y);
}

double dot(vec a, vec b) {
  return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
  return v.x * v.x + v.y * v.y;
}

double distToLine(point p, point a, point b, point &c) {
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  c = translate(a, scale(ab, u));
  return dist(p, c);
}

double distToLineSegment(point p, point a, point b, point &c) {
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  if (u < 0.0) {
    c = point(a.x, a.y);
    return dist(p, a);
  }
  if (u > 1.0) {
    c = point(b.x, b.y);
    return dist(p, b);
  }
  return distToLine(p, a, b, c);
}

/** BONUS: FILL THIS FUNCTION */
bool lineSegmentIntersection(point p1, point p2, point p3, point p4, point &x) {

  point intersection_point;
  point dummy;
  line l1, l2;
  pointsToLine(p1, p2, l1);
  pointsToLine(p3, p4, l2);
  return (intersection(l1, l2, intersection_point) && fabs(distToLineSegment(intersection_point, p1, p2, dummy)) < EPS
      && fabs(distToLineSegment(intersection_point, p3, p4, dummy)) < EPS);

}

double angle(point a, point o, point b) {
  vec oa = toVec(o, a), ob = toVec(o, b);
  return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b) {
  return a.x * b.y - a.y * b.x;
}

bool ccw(point p, point q, point r) {
  return cross(toVec(p, q), toVec(p, r)) >= 0;
}

bool collinear(point p, point q, point r) {
  return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

/** --- CIRCLES --- */

int insideCircle(point p, point center, double radius) {
  double dx = p.x - center.x, dy = p.y - center.y;
  double euc = dx * dx + dy * dy, rsq = radius * radius;
  return euc < rsq ? 0 : fabs(euc - rsq) < EPS ? 1 : 2;
}

double chord(double radius, double angle) {
  return sqrt(2 * radius * radius * (1 - cos(angle)));
}

// given 2 points and radius, returns a circle with center c (if it exists) and point p1, p2 on it's circumference
bool circle2PtsRad(point p1, point p2, double r, point &c) {
  double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
  double det = r * r / d2 - 0.25;
  if (det < 0.0)
    return false;
  double h = sqrt(det);
  c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
  c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
  return true;
}  // to get the other center, reverse p1 and p2

/** --- TRIANGLES (& CIRCLES) --- */

double areaOfTri(point v1, point v2, point v3) {
  return fabs(v1.x * (v2.y - v3.y) + v2.x * (v3.y - v1.y) + v3.x * (v1.y - v2.y)) / 2.0;
}

double areaOfTri(double a, double b, double c) {
  double s = 0.5 * (a + b + c);
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

double rCircumCircle(double ab, double bc, double ca) {
  return ab * bc * ca / (4.0 * areaOfTri(ab, bc, ca));
}

double rCircumCircle(point a, point b, point c) {
  return rCircumCircle(dist(a, b), dist(b, c), dist(c, a));
}

double rInCircle(double ab, double bc, double ca) {
  return areaOfTri(ab, bc, ca) / (0.5 * (ab + bc + ca));
}

double rInCircle(point a, point b, point c) {
  return rInCircle(dist(a, b), dist(b, c), dist(c, a));
}

int inCircle(point p1, point p2, point p3, point &ctr, double &r) {
  r = rInCircle(p1, p2, p3);
  if (fabs(r) < EPS)
    return 0;  // no inCircle center

  line l1, l2;  // compute these two angle bisectors
  double fraction = dist(p1, p2) / dist(p1, p3);
  point p = translate(p2, scale(toVec(p2, p3), fraction / (1 + fraction)));
  pointsToLine(p1, p, l1);

  fraction = dist(p2, p1) / dist(p2, p3);
  p = translate(p1, scale(toVec(p1, p3), fraction / (1 + fraction)));
  pointsToLine(p2, p, l2);

  intersection(l1, l2, ctr);  // get their intersection point
  return 1;
}

/** --- POLYGONS --- */

double area(const vector<point> &P) {
  double result = 0.0, x1, y1, x2, y2;
  for (int i = 0; i < (int) P.size() - 1; i++) {
    x1 = P[i].x;
    x2 = P[i + 1].x;
    y1 = P[i].y;
    y2 = P[i + 1].y;
    result += (x1 * y2 - x2 * y1);
  }
  return fabs(result) / 2.0;
}

double perimeter(const vector<point> &P) {
  double result = 0.0;
  for (int i = 0; i < (int) P.size() - 1; i++)  // remember that P[0] = P[n-1]
    result += dist(P[i], P[i + 1]);
  return result;
}

bool inPolygon(point pt, const vector<point> &P) {
  if ((int) P.size() == 0)
    return false;
  double sum = 0;  // assume the first vertex is equal to the last vertex
  for (int i = 0; i < (int) P.size() - 1; i++) {
    if (ccw(pt, P[i], P[i + 1]))
      sum += angle(P[i], pt, P[i + 1]);     // left turn/ccw
    else if (collinear(P[i], pt, P[i + 1]))
      return pt == P[i] || pt == P[i + 1] || fabs(distToLineSegment(pt, P[i], P[i + 1], dummy)) < EPS;                          // collinear
    else
      sum -= angle(P[i], pt, P[i + 1]);     // right turn/cw
  }
  return fabs(fabs(sum) - 2 * PI) < EPS;
}

point pivot(0, 0);
bool angleCmp(const point a, const point b) {  // angle-sorting function
  if (collinear(pivot, a, b))  // special case
    return dist(pivot, a) < dist(pivot, b);  // check which one is closer

  double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
  double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
  return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

int dcmp(double a, double b) {
  if (fabs(a - b) <= EPS)
    return 0;
  else if (a > b)
    return 1;
  else
    return -1;
}

vector<point> pts;
vector<pair<point, point>> segments;

int main() {
  fastIO;
  read;
  write;
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
      cur = distToLineSegment(p, segments[i].first, segments[i].second, dum);
      if (dcmp(cur, minDist) <= 0) {
        minDist = cur;
        ans = dum;
      }
    }
    cout << ans.x << '\n' << ans.y << endl;
  }
  return 0;
}

