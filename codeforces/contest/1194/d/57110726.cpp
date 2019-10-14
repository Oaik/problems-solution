#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 5e4 + 9, M = 4e4 + 9, OO = 1e9;
int arr[26];
int main() {
  fastIO;
  // freopen("input.in", "rt", stdin);//  freopen("output.in", "wt", stdout);
  int t, n, x;
  cin >> t;
  while(t--) {
    cin >> n >> x;
    if(n == 0) {
      cout << "Bob\n";
      continue;
    }
    if(x % 3 != 0) {
      if(n % 3 == 0)
        cout << "Bob\n";
      else
        cout << "Alice\n";
    } else {
      if(n % (x+1) != x && (n % (x+1)) % 3 == 0)
        cout << "Bob\n";
      else
        cout << "Alice\n";
    }
  }
  return 0;
}
