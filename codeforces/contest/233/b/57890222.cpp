#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e8 + 1, OO = 1e9;

int main() {
  fastIO;
  unsigned ll n;
  cin >> n;
  for (ll i = max((ll)sqrt(n) - 100, 1ll); i <= sqrt(n) + 100; ++i) {
    ll temp = i, cnt = 0;
    while(temp) {
      cnt += temp % 10;
      temp /= 10;
    }
    ll sum = i * i + cnt * i - n;
    if(sum != 0)
      continue;
    cout << i;
    return 0;
  }
  cout << -1;
  return 0;
}
