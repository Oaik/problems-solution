#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(2), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9;

int dcmp(double x, double y) {
  if(fabs(x - y) <= EPS) return 0;
  else if(x > y) return 1;
  else return -1;
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
  double res = c * c + b * b - a*a;
  res /= (2 * c * b);
  if (res > 1)
    res = 1;
  if (res < -1)
    res = -1;
  return acos(res) * 180.0/PI;
}


bool isCollinear(point a, point b, point c) {
  return fabs( cp(b-a, c-a) ) < EPS;
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

pair<double, point> findCircle(point a, point b, point c) {
  //create median, vector, its prependicular
  point m1 = (b+a)*0.5, v1 = b-a, pv1 = point(v1.Y, -v1.X);
  point m2 = (b+c)*0.5, v2 = b-c, pv2 = point(-v2.Y, v2.X);
  point end1 = m1+pv1, end2 = m2+pv2, center;
  intersectSegments(m1, end1, m2, end2, center);
  return make_pair( length(a-center), center );
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


const int MAX = 100000+9;
point pnts[MAX], r[3], cen;
double rad;
int ps, rs; // ps = n, rs = 0, initially

// Pre condition
// random_shuffle(pnts, pnts+ps);   rs = 0;
void MEC() {
  if(ps == 0 && rs == 2) {
    cen = (r[0]+r[1])/2.0;
    rad = length(r[0]-cen);
  }
  else if(rs == 3) {
    pair<double, point> p = findCircle(r[0], r[1], r[2]);
    cen = p.second;
    rad = p.first;
  }
  else if(ps == 0) {
    cen = r[0]; // sometime be garbage, but will not affect
    rad = 0;
  }
  else {
    ps--;
    MEC();

    if(length(pnts[ps]-cen) > rad) {
      r[rs++] = pnts[ps];
      MEC();
      rs--;
    }

    ps++;
  }
}


int main() {
  fastIO;
  int n, t;
  cin >> t;
  while(t--) {
    cin >> n;
    double a, b;
    ps = n, rs = 0, rad = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a >> b;
      pnts[i] = point(a, b);
    }
    random_shuffle(pnts, pnts+ps);
    MEC();
    cout << rad << '\n';
    cout << cen.X << ' ' << cen.Y << '\n';
  }
  return 0;
}

