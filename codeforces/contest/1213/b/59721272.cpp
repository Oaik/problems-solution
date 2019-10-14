#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, M = 1e4 + 9, OO = 1e9 + 9, MOD = 1e9 + 7;

int arr[N], arr2[N];

int main() {
  fastIO;
  int t, n;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    int prv = arr[n - 1];
    int cnt = 0;
    for (int i = n - 2; i >= 0; --i) {
      if(arr[i] > prv) {
        ++cnt;
      } else {
        prv = arr[i];
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}
