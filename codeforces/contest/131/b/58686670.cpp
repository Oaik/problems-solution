#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9;

ll freq[N][29];
int arr[N];

int main() {
  fastIO;
  int n, x;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    arr[i] = x;
    if(x < 0)
      x = abs(x) + 10;
    ++freq[i][x];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= 25; ++j)
      freq[i][j] += freq[i-1][j];
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    x = arr[i];
    if(x <= 0)
      x = abs(x);
    else
      x += 10;
    ans += freq[n][x] - freq[i][x];
  }
  cout << ans;
  return 0;
}
