#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(10), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1179858 + 9, OO = 1e9;

set<double> st;

int main() {
  fastIO;
  int n;
  cin >> n;
  vector<double> vec;
  for (int i = 0; i < n; ++i) {
    double a, b, c, ang;
    cin >> a >> b;
    ang = b / a;
    c = atan(ang) * 180 / PI;
    c = fabs(c);
    if(a <= 0 && b <= 0 && (a != 0 || b != 0))
      c += 180;
    else if(a < 0)
      c = 180 - c;
    else if(b < 0)
      c = 360 - c;
    st.insert(c);
//    cout << c << endl;
  }
  for(double it: st)
    vec.push_back(it);
  n= vec.size();
  if(n == 1)
    cout << 0;
  else {
    double ans = min(vec[n-1] - vec[0], min(360 - (vec[n-1] - vec[n - 2]), 360 - (vec[1] - vec[0])));
    for (int i = 1; i < n-1; ++i) {
      ans = min(ans, 360 - (vec[i+1] - vec[i]) );
    }
    cout << ans;
  }
  return 0;
}
