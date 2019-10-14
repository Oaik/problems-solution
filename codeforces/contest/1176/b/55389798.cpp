#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(4);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, OO = 1e9;

int main() {
  debug();
  int t, n, a, divA, divB, divC;
  cin >> t;
  while(t--) {
    cin >> n;
    divA = 0, divB = 0, divC = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a;
      if(a % 3 == 0)
        ++divA;
      else if (a % 3 == 1)
        ++divB;
      else
        ++divC;
    }
    int mn = min(divB, divC);
    divA += mn;
    divB -= mn, divC -= mn;
    divA += (divB / 3) + (divC/ 3);
    cout << divA << '\n';
  }
  return 0;
}