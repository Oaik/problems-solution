#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  // freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(4);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
int const N = 2e5 + 9, OO = 1e9;

int main() {
  debug();
  int t, n, k;
  double p;
  cin >> t;
  while(t--) {
    cin >> n >> p >> k;
    ll i = 0;
    double ans = 0, temp = OO;
    while(fabs(ans - temp) > EPS) {
      temp = ans;
      ans += p*(pow(1-p, n*i + k - 1));
      ++i;
    }
    cout << ans << endl;
  }
}

