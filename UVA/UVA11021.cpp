#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "r", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(7), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 2e3 + 9, M = 2e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

double dp[1009], P[1009];
int n, m, k;

int main() {
  fastIO;
  read("input.in");
//  write("input.in");
  int t;
  cin >> t;
  for (int idx = 1; idx <= t; ++idx) {
    clr(dp, 0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
      cin >> P[i];
    dp[k] = P[0];
    for (int i = k-1; i >= 1; --i) {
      for (int j = 0; j < n; ++j) {
        if(!j)
          dp[i] += P[j];
        else
          dp[i] += pow(dp[i+1], j) * P[j];
      }
    }
    cout << "Case #" << idx << ':' << ' ' << pow(dp[1], m) << '\n';
  }
  return 0;
}

