#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
double const EPS = 1e-15, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e5;

char R[] = { 'R', 'G', 'B' }, G[] = { 'G', 'B', 'R' }, B[] = { 'B', 'R', 'G' };

int main() {
  fastIO;
  int q;
  string str;
  cin >> q;
  while (q--) {
    int n, m, l, k, cnt, ans = OO, c1 = 0, c2, c3;
    cin >> n >> m;
    cin >> str;
    l = n - m;
    for (int i = 0; i <= l; ++i) {
      k = i + m, cnt = 0, c1 = 0,c2 = 0,c3 = 0;
      for (int j = i; j < k; ++j) {
        c1 += (R[cnt] != str[j]);
        c2 += (G[cnt] != str[j]);
        c3 += (B[cnt] != str[j]);
        ++cnt;
        cnt %= 3;
      }
      ans = min(ans, min(c1, min(c2, c3)));
    }
    cout << ans << '\n';
  }
  return 0;
}
