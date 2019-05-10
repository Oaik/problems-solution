#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
const int N = 1e3 + 9, OO = 1e9;

char arr[109][109];

double areaOfTri(double x1, double y1, double x2, double y2, double x3, double y3) {
  return fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;
}

int main() {
  debug();
  ll w, h, xC, yC, rC, x1, x2, y1, y2, dist;
  cin >> h >> w;
  cin >> xC >> yC >> rC;
  rC *= rC;
  for (int i = 0; i < 103; ++i) {
    for (int j = 0; j < 103; ++j) {
      arr[i][j] = '.';
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      dist = (i - xC) * (i - xC) + (j - yC) * (j - yC);
      if (dist <= rC)
        arr[j][i] = '#';
    }
  }
  cin >> x1 >> y1 >> x2 >> y2;
  double x3 = x1 + x2 + y1 - y2, y3 = x2 - x1 + y1 + y2, x4 = x1 + x2 + y2 - y1, y4 = x1 - x2 + y1 + y2;
  x3 /= 2, y3 /= 2, x4 /= 2, y4 /= 2;
  double areaRect = areaOfTri(x1, y1, x3, y3, x2, y2) + areaOfTri(x1, y1, x4, y4, x2, y2);
//  areaRect /= 2;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      double totalArea = areaOfTri(x1, y1, i, j, x4, y4) + areaOfTri(x4, y4, i, j, x2, y2)
          + areaOfTri(x2, y2, i, j, x3, y3) + areaOfTri(i, j, x3, y3, x1, y1);
      if(fabs(totalArea - areaRect) <= EPS)
        arr[j][i] = '#';
    }
  }
  for (int i = 0; i < w; ++i) {
    for (int j = 0; j < h; ++j) {
      cout << arr[i][j];
    }
    cout << '\n';
  }
}

