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
  cout << fixed << setprecision(12);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, OO = 1e9;

string arr[9];
int pre[9];

int main() {
  debug();
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  iota(pre, pre + k, 0);
  int ans = 1e9;
  do {
    int mx = 0, mn = 1e9;
    for (int i = 0; i < n; ++i) {
      string srr("0", k);
      for (int j = 0; j < k; ++j)
        srr[j] = arr[i][pre[j]];
      mx = max(mx, stoi(srr));
      mn = min(mn, stoi(srr));
    }
    ans = min(ans, mx - mn);
  } while(next_permutation(pre, pre + k));
  cout << ans;
  return 0;
}
