#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-15, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e5;

int arr[N];
vector<int> idx;

int main() {
  fastIO;
  // freopen("input.in", "rt", stdin);//  freopen("output.in", "wt", stdout);
  int q;
  cin >> q;
  while(q--) {
    int n, x, y, a , b, c, d;
    int X1 = OO,X = -OO, Y = -OO, Y1 = OO;
    cin >> n;
    bool can = 0;
    for (int i = 0; i < n; ++i) {
      cin >> x >> y >> a >> b >> c >> d;
      if(!a) {
        X = max(X, x);
      }
      if(!c) {
        X1 = min(X1, x);
      }
      if(!b) {
        Y1 = min(Y1, y);
      }
      if(!d) {
        Y = max(Y, y);
      }
    }
    if(can || (X1 < X) || (Y > Y1))
      cout << 0 << '\n';
    else
      cout << 1 << ' ' << X << ' ' << Y << '\n';
  }
  return 0;
}
