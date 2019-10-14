#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout << fixed << setprecision(3)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1.5 * (1e7 + 9), OO = 1e9, v = 1e6;
int freq[N];
bool vis[N];
int main() {
  fastIO;
//  freopen("input.in", "rt", stdin); // freopen("output.in", "wt", stdout);
  int n, a, mx = 0, g = -1;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if(g == -1)
      g = a;
    g = __gcd(g, a);
    mx = max(mx, a);
    ++freq[a];
  }
  int ans = -1, cnt = 0;
  for (int i = g + 1; i <= mx; ++i) {
    if(vis[i])
      continue;
    cnt = 0;
    for (int j = i; j <= mx; j += i)
      cnt += freq[j], vis[j] = 1;
    if(cnt > 0 && cnt < n)
      ans = max(cnt, ans);
    if(i > mx)
      break;
  }
  if(ans == -1)
    cout << ans;
  else
    cout << n - ans;
  return 0;
}
