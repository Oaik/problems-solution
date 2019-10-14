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

int arr[1009], vals[1009];
vector<pair<int, pair<int, int>>> vec;

int main() {
  debug();
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 0)
      t = 1;
    else
      t = 0;
    vec.push_back( { t, { a, b } });
  }
  sort(all(vec));
  for (auto it : vec) {
    int t = it.first, a = it.second.first, b = it.second.second, val;
    if (t == 0) {
      val = 1;
      for (int i = a + 1; i <= b; ++i)
        arr[i] = val;
    } else {
      val = -1;
      bool can = 0;
      for (int i = a + 1; i <= b; ++i) {
        if (arr[i] == val) {
          can = 1;
          break;
        }
      }
      if(can)
        continue;
      for (int i = a + 1; i <= b; ++i) {
        if (arr[i] == 0) {
          arr[i] = val;
          can = 1;
          break;
        }
      }
      if (!can) {
        cout << "NO";
        return 0;
      }
    }
  }
  int mx = 1009;
  for (int i = 1; i <= n; ++i) {
    if (arr[i] == -1) {
      --mx;
      vals[i] = mx;
    } else
      vals[i] = mx;
  }
  cout << "YES\n";
  for (int i = 1; i <= n; ++i)
    cout << vals[i] << ' ';
  return 0;
}
