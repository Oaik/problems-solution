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

map<int, int> mp, app;
int arr[N];

int main() {
  fastIO;
  int n, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    ++mp[arr[i]];
    if(mp[arr[i]] == 2)
      ++cnt;
  }
  int ans = OO;
  if(cnt == 0)
    ans = 0;
  for (int i = 0; i < n; ++i) {
    app = mp;
    int cur = cnt;
    for (int j = i; j < n; ++j) {
      --app[arr[j]];
      if(app[arr[j]] == 1)
        --cur;
      if(!cur) {
        ans = min(ans, j - i + 1);
      }
    }
  }
  cout << ans;
  return 0;
}
