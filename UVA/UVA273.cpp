#include <bits/stdc++.h>
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 15, OO = 1e9;
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
using namespace std;


#define X real()
#define Y imag()
#define cp(a,b)                 ( (conj(a)*(b)).imag() )  // a*b sin(T), if zero -> parllel

typedef complex<double> point;
struct seg {
  point a, b;
};
seg arr[N];
bool dp[N][N];
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
int main() {
  fastIO;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    clr(dp, 0);
    int x, y;
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      arr[i].a = point(x, y);
      cin >> x >> y;
      arr[i].b = point(x, y);
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        dp[i][j] = dp[j][i] = intersect(arr[i].a, arr[i].b, arr[j].a, arr[j].b);
      }
      dp[i][i] = 1;
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          dp[i][j] |= (dp[i][k] & dp[k][j]);
        }
      }
    }
    while (cin >> x >> y, (x + y)) {
      if ((dp[x - 1][y - 1]))
        cout << "CONNECTED\n";
      else
        cout << "NOT CONNECTED\n";
    }
    if (t)
      cout << '\n';
  }
}

