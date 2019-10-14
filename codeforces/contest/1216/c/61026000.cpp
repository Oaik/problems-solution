#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 5e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

bool valid(int x1, int y1, int x2, int y2) {
  if(x1 >= x2 || y1 >= y2)
    return 0;
  return 1;
}

ll areaRect(int x1, int y1, int x2, int y2) {
  if(!valid(x1, y1, x2, y2))
    return 0;
  ll len = (x2 - x1), width = y2 - y1;
  return (len * width);
}

int main() {
  fastIO;
  int a, b, c, d;
  int x1, y1, x2, y2,
      x3, y3, x4, y4;
  cin >> a >> b >> c >> d;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> x3 >> y3 >> x4 >> y4;

  int lx1, ly1, ux1, uy1,
      lx2, ly2, ux2, uy2,
      ix1, iy1, ix2, iy2;

  lx1 = max(a, x1);
  ly1 = max(b, y1);
  ux1 = min(c, x2);
  uy1 = min(d, y2);
  ll area1 = areaRect(lx1, ly1, ux1, uy1);

  lx2 = max(a, x3);
  ly2 = max(b, y3);
  ux2 = min(c, x4);
  uy2 = min(d, y4);
  ll area2 = areaRect(lx2, ly2, ux2, uy2);

  ix1 = max(lx1, lx2);
  iy1 = max(ly1, ly2);
  ix2 = min(ux1, ux2);
  iy2 = min(uy1, uy2);
  ll areaInter = areaRect(ix1, iy1, ix2, iy2);

  ll totalArea = area1 + area2 - areaInter,
     areaWhite = areaRect(a, b, c, d);

  if(totalArea != areaWhite)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
