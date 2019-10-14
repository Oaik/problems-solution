#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e3 + 9, M = 2e5 + 2, OO = 1e9 + 9, MOD = 1e9 + 7;

bool arr[N];
int vis[N];
vector<int> vec;

int main() {
  fastIO
  int n, r;
  cin >> n >> r;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    if(arr[i]) {
      for (int j = max(1, i - r + 1); j <= min(i + r - 1, n); ++j)
        ++vis[j];
      vec.push_back(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
   if(!vis[i] && !arr[i]) {
     cout << -1;
     return 0;
   }
  }
  int m = vec.size();
  for (int i = 1; i <= n; ++i) {
    if(!arr[i])
      continue;
    bool can = 1;
    for (int j = max(1, i - r + 1); j <= min(i + r - 1, n); ++j) {
      if(vis[j] == 1) {
        can = 0;
        break;
      }
    }
    if(can) {
      for (int j = max(1, i - r + 1); j <= min(i + r - 1, n); ++j)
        --vis[j];
     --m;
    }
  }
  cout << m;
  return 0;
}
