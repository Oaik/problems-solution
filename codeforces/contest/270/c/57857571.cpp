#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 3e5 + 9, OO = 1e9;

int main() {
  fastIO;
  int n;
  ll a, b;
  double ans = 1;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
//    double cc = ceil((log2(pow(2, a) * pow(2, a) * b)) / 2);
    double cc = (2*a + (log2(b+(b&1))));
    cc /= 2;
    ans = max(ans, ceil(cc));
  }
  cout << ans;
}
