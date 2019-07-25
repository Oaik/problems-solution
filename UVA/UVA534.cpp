#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(3), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
double const EPS = 1e-15, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e5;

int ptsX[201], ptsY[201];
int dist[201][201];


int main() {
  fastIO;
  int n, cnt = 1;
  while(cin >> n, n) {
    for (int i = 0; i < n; ++i) {
      cin >> ptsX[i] >> ptsY[i];
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j < n; ++j) {
        int dis = (ptsX[i] - ptsX[j]) * (ptsX[i] - ptsX[j]) + (ptsY[i] - ptsY[j]) * (ptsY[i] - ptsY[j]);
        dist[i][j] = dis;
        dist[j][i] = dis;
      }
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
        }
      }
    }
    double ans = sqrt(dist[0][1]);
    cout << "Scenario #" << cnt << '\n';
    cout << "Frog Distance = " << ans << '\n' << '\n';
    ++cnt;
  }
  return 0;
}

