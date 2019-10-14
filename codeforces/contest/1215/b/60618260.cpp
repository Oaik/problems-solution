#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 3e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

int main() {
  fastIO;
  int n, a;
  cin >> n;
  ll totalPos = 0, totalNeg = 0;
  int kamPos = 0, kamNeg = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if(a > 0) {
      totalPos += kamPos;
      totalNeg += kamNeg;

      ++kamPos;
      ++totalPos;
    } else {
      totalNeg += kamPos;
      totalPos += kamNeg;

      int temp = kamPos;
      kamPos = kamNeg;
      kamNeg = temp;
      ++kamNeg;
      ++totalNeg;
    }
  }
  cout << totalNeg << ' ' << totalPos;
  return 0;
}
