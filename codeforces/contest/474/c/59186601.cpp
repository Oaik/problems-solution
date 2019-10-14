#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 5e3 + 9, OO = 1e9 + 9;

typedef complex<double> point;

#define X real()
#define Y imag()
#define cp(a,b)                 ( (conj(a)*(b)).imag() )  // a*b sin(T), if zero -> parllel
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)

point rotate_point(point Q,double angle,point p) {
  int s = 1;
  int c = 0;

  p = point(p.X - Q.X, p.Y - Q.Y);

  double xnew = p.X * c - p.Y * s;
  double ynew = p.X * s + p.Y * c;

  p = point(xnew + Q.X, ynew + Q.Y);

  return p;
}

vector<pair<point, point>> vec;
int ans = -1;

bool isSqure(point A, point B, point C, point D) {
  point M((A.X + B.X + C.X + D.X) / 4.0, (A.Y + B.Y + C.Y + D.Y) / 4.0);
  point v1 = A - M;
  point v2(-v1.Y, v1.X);
  point X1(M - v1), Y1(M-v2), Z1(M+v2);
  set<pair<double, double>> st;
  st.insert({A.X, A.Y});
  st.insert({B.X, B.Y});
  st.insert({C.X, C.Y});
  st.insert({D.X, D.Y});
  if(st.size() != 4)
    return 0;
  if((B == X1 && C == Y1 && D == Z1) ||
      (B == X1 && C == Z1 && D == Y1) ||
      (B == Y1 && C == X1 && D == Z1) ||
      (B == Y1 && C == Z1 && D == X1) ||
      (B == Z1 && C == X1 && D == Y1)||
      (B == Z1 && C == Y1 && D == X1))
    return 1;
  return 0;
}

void backtrack(int x, int cnt, vector<point> &vv) {
  if(x == 4) {
    if(isSqure(vv[0], vv[1], vv[2], vv[3]) && cnt < ans)
      ans = cnt;
    return;
  }
  vv.push_back(vec[x].first);
  backtrack(x+1, cnt, vv);
  vv.pop_back();
  for (int i = 1; i < 4; ++i) {
    point cur = vec[x].first;
    for (int j = 0; j < i; ++j)
      cur = rotate_point(vec[x].second, 90, cur);
    vv.push_back(cur);
    backtrack(x+1, cnt + i, vv);
    vv.pop_back();
  }
}

int main() {
  fastIO;
  int n, x, y, a, b;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    vec.clear();
    ans = OO;
    for (int i = 0; i < 4; ++i) {
      cin >> x >> y >> a >> b;
      point u(x, y), v(a, b);
      vec.push_back({u, v});
    }
    vector<point> vvv;
    backtrack(0, 0,vvv);
    if(ans == OO)
      ans = -1;
    cout << ans << '\n';
  }
  return 0;
}
