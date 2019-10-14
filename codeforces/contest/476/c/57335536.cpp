#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define readIn freopen("input.in", "rt", stdin);
#define writeOut freopen("output.in", "wt", stdout);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e7 + 9, OO = 1e9;

int main() {
  fastIO;
  const ll MOD = 1e9 + 7;
  ll a, b;
  cin >> a >> b;
  ll total = 0;
  total = ((b - 1) * (b)) / 2;
  total %= MOD;
  ll num1 = a + 1, num2 = a;
  if(num1 & 1) num2 = num2 >> 1;
  else num1 = num1 >> 1;
  total *= ( (((num1 * num2) % MOD) * b ) % MOD + (a % MOD) ) % MOD;
  cout << total % MOD;
  return 0;
}
