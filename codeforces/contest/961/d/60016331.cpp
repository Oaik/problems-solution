#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 2e5 + 2, OO = 1e9 + 9, MOD = 1e9 + 7;

typedef complex<long long> point;
#define cp(a,b)                 ( (conj(a)*(b)).imag() )  // a*b sin(T),

bool isCollinear(point a, point b, point c) {
  return abs( cp(b-a, c-a) ) < EPS;
}

bool check(vector<point> pt) {
  int n = pt.size();
  point p1, p2;
  for (int i = 0; i < 3; ++i) {
    p1 = pt[i];
    p2 = pt[(i + 1) % 3];
    bool can = 1;
    for (int i = 0; i < n && can; ++i) {
      if(!isCollinear(p1, p2, pt[i]))
        can = 0;
    }
    if(can)
      return 1;
  }
  return 0;
}

point pts[N];

int main() {
  fastIO
  int n;
  cin >> n;
  if(n <= 4) {
    cout << "YES\n";
    return 0;
  }
  ll x, y;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    pts[i] = point(x, y);
  }
  point p1, p2;
  for (int i = 0; i < 3; ++i) {
    p1 = pts[i];
    p2 = pts[(i + 1) % 3];
    vector<point> pp;
    for (int i = 0; i < n; ++i) {
      if(!isCollinear(p1, p2, pts[i]))
        pp.push_back(pts[i]);
    }
    if(pp.size() <= 2 || check(pp)) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
