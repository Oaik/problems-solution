#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e3 + 9, M = 1e6 + 19, OO = 1e9 + 9;

int main() {
  fastIO;
 ll a, b, n;
 int t;
 cin >> t;
 while(t--) {
   cin >> a >> b >> n;
   ll arr[3];
   arr[0] = a, arr[1] = b, arr[2] = (a ^ b);
   cout << arr[n % 3] << '\n';
 }
  return 0;
}
