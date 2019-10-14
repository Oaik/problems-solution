#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e3 + 9, OO = 1e9;

int main() {
  fastIO;
  int a, b;
  cin >> a >> b;
  string cmp = to_string(b);
  while(1) {
    ++a;
    string str;
    string res = to_string(a);
    for(auto c: res)
      if(c == '7' || c == '4')
        str += c;
    if(str == cmp) {
      cout << res;
      return 0;
    }
  }
  return 0;
}
