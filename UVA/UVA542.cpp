#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "r", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(2), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 2e3 + 9, M = 2e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

double dp[19][5], val[19][19];
string arr[19];

int main() {
  fastIO;
//  read("input.in");
//  write("input.in");
  map<string, int> mp;
  string str;
  for (int i = 0; i < 16; ++i) {
    cin >> arr[i];
    mp[arr[i]] = i;
  }
  for (int i = 0; i < 16; ++i)
    for (int j = 0; j < 16; ++j)
      cin >> val[i][j], val[i][j] = 1.0 * val[i][j] / 100.0;

  for (int i = 0; i < 16; ++i)
    dp[i][0] = 1;

  for (int k = 1; k <= 4; ++k) {  // 2, 4, 8
    for (int l = 0; l < 16; l += (1 << k)) {
      int start = l, end = (l + (1 << k)), mid = (start + end) / 2;
      for (int i = l; i < mid; ++i) {
        for (int j = mid; j < end; ++j) {
          dp[i][k] += 1.0 * val[i][j] * dp[j][k - 1] * dp[i][k - 1];
          dp[j][k] += 1.0 * val[j][i] * dp[i][k - 1] * dp[j][k - 1];
        }
      }
    }
  }

  for (int i = 0; i < 16; ++i) {
    cout << arr[i];
    for (int j = arr[i].size(); j <= 10; ++j)
      cout << ' ';
    cout << "p=" << dp[i][4] * 100 << '%' << '\n';
  }
  return 0;
}

