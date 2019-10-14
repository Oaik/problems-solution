#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);   //freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-6, PI = acos(-1);
int const N = 1e5 + 9, M = 1e5 + 9, OO = 1e7;

int freqColors[N], cnt[N];

int main() {
  debug();
  int n, a, v, ans = 0, mx = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    v = freqColors[a];
    --cnt[v];
    ++freqColors[a], ++v;
    ++cnt[v];
    mx = max(mx, v);
    if (cnt[i] == 1 || cnt[1] == i + 1)
      ans = i + 1;
    if (cnt[1] == 1 && mx * cnt[mx] == i )
      ans = i + 1;
    if (cnt[mx] == 1 && cnt[mx - 1] * (mx - 1) == i - mx + 1)
      ans = i + 1;
  }
  cout << ans;
}
