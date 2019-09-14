#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, M = 1e6 + 1, OO = 1e9 + 1, MOD = 1e9 + 7;
const unsigned ll inf = 9e18;

int main() {
  fastIO
  unsigned ll A, B;
  while(cin >> A >> B, A || B) {
    unsigned ll ansA = A / 5, ansB = B / 5;
    cout << ansB - ansA + 1 << '\n';
  }
  return 0;
}

