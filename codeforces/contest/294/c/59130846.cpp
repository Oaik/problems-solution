// idea of Dr.Mostafa saad
// https://www.youtube.com/watch?v=xB6St1GAKUg

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(2), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9;
const int MOD = 1e9 + 7;

ll C[1001][1001], pows[1001];

void pascalTri() {
  int mx = 1001;
  for (int i = 0; i < mx; ++i) {
    for (int j = 0; j <= i; ++j) {
      if(j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
    }
  }
}

int main() {
  fastIO;

  pascalTri();
  pows[0] = pows[1] = 1;
  for (int i = 2; i < 1001; ++i)
    pows[i] = (2 * pows[i - 1]) % MOD;

  int n, m, a;
  cin >> n >> m;
  vector<int> vec;
  for (int i = 0; i < m; ++i) {
    cin >> a;
    vec.push_back(a);
  }
  sort(all(vec));

  vector<int> diff;
  diff.push_back(vec[0] - 1);
  for (int i = 1; i < m; ++i)
    diff.push_back(vec[i] - vec[i-1] - 1);
  diff.push_back(n - vec.back());

  ll ans = 1;
  for (int i = 1; i < m; ++i)
    ans = (ans * pows[diff[i]]) % MOD;

  int sum = diff[0];
  for (int i = 1; i <= m; ++i) {
    sum += diff[i];
    ll p = C[sum][diff[i]];
    ans = (ans * p) % MOD;
  }

  cout << ans;
  return 0;
}
