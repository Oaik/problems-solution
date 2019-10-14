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
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9;

int arr[1001];

int main() {
  debug();
  ll a, b, x, y;
  cin >> a >> b >> x >>y;
  ll g = __gcd(x, y);
  x /= g, y /= g;
  ll numofX = a / x, numofY = b / y;
  cout << min(numofX, numofY);
}