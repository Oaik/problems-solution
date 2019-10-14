#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e4 + 9, M = 3e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

int main() {
  fastIO;
//  read;
  string str;
  cin >> str;
  char c = 'z' + 1;
  for (int i = 0; i < (int)str.size(); ++i) {
    if(str[i] > c)
      cout << "Ann\n";
    else
      cout << "Mike\n";
    c = min(c, str[i]);
  }
  return 0;
}
