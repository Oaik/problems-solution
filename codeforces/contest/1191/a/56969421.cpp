#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout << fixed << setprecision(0)
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e6 + 9, OO = 1e9, v = 1e6;
int main() {
  fastIO;
//  freopen("input.in", "rt", stdin); // freopen("output.in", "wt", stdout);
  int n;
  cin >> n;
  int mod = n % 4;
  if(mod == 2) {
    cout << 1 << ' ' << 'B';
  } else if(mod == 0) {
    cout << 1 << ' ' << 'A';
  } else if(mod == 3) {
    cout << 2 << ' ' << 'A';
  } else {
    cout << 0 << ' '<< 'A';
  }
  return 0;
}
