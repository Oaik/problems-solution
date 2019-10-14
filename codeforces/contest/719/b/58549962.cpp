#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e6 + 9, OO = 1e9;

int main() {
  fastIO;
  int n;
  string str;
  cin >> n >> str;
  int r1 = 0, b1 = 0;
  for (int i = 0; i < n; ++i) {
    if(i & 1) {
      if(str[i] == 'r')
        ++r1;
    } else {
      if(str[i] == 'b')
        ++b1;
    }
  }
  int ans = min(r1, b1);
  r1 -= ans;
  b1 -= ans;
  ans += r1 + b1;
  r1 = b1 = 0;
  for (int i = 0; i < n; ++i) {
    if(i & 1) {
      if(str[i] == 'b')
        ++b1;
    } else {
      if(str[i] == 'r')
        ++r1;
    }
  }
  int ans1 = min(r1, b1);
  r1 -= ans1;
  b1 -= ans1;
  ans1 += r1 + b1;
  cout << min(ans1, ans);
  return 0;
}
