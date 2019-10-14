#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, M = 2e5 + 2, OO = 1e9 + 9, MOD = 1e9 + 7;

int arr[N];

int main() {
  fastIO
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  reverse(arr, arr + n);
  --m;
  int cur = k, take = 0;
  bool lsa = 1;
  for (int i = 0; i < n; ++i) {
    lsa = 0;
    if(arr[i] > cur) {
      while(m) {
        --m;
        cur = k;
        if(arr[i] <= cur) {
          cur -= arr[i];
          ++take;
          lsa = 1;
          break;
        }
      }
    } else {
      cur -= arr[i];
      ++take;
      lsa = 1;
    }
    if(!lsa)
      break;
  }
  cout << take;
  return 0;
}
