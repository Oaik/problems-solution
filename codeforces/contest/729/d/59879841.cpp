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

int main() {
  fastIO
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  string str;
  cin >> str;
  vector<int> pos;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {

    if(str[i] == '0') {
      ++cnt;
      if(cnt == b) {
        pos.push_back(i + 1);
        cnt = 0;
      }
    } else
      cnt = 0;
  }
  int mn = pos.size() - a + 1;
  cout << mn << '\n';
  for (int i = 0; i < mn; ++i)
    cout << pos[i] << ' ';
  return 0;
}
