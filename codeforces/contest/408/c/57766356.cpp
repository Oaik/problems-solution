#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
double const EPS = 1e-15, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e5;

int main() {
  fastIO;
  ll a, b;
  cin >> a >> b;
  int dist = a * a + b * b, dist2;
  for (int i = -a + 1; i < a; ++i) {
    if(i == 0)
      continue;
    int y1 = (a * a) - (i * i);
    int sqrtY1 = sqrt(y1);
    if(sqrtY1 * sqrtY1 != y1)
      continue;
    y1 = sqrtY1;
    if(y1 == 0)
      continue;
    for (int j = -b + 1; j < b; ++j) {
      if(j == 0 || j == i)
        continue;
      int y2 = (b * b) - (j * j);
      int sqrtY2 = sqrt(y2);
      if(sqrtY2 * sqrtY2 != y2)
        continue;
      y2 = sqrtY2;
      if(y2 == 0 || y2 == y1)
        continue;
      dist2 = (i - j) * (i - j) + (y1 - y2) * (y1 - y2);
      if(dist == dist2) {
        cout << "YES\n";
        cout << "0 0\n";
        cout << i << ' ' << y1 << '\n';
        cout << j << ' ' << y2 << '\n';
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}
