#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)    ((v).begin()),((v).end())
#define clr(a,b)  memset(a,b,sizeof(a))
const double EPS = 1e-8, pi = acos(-1);
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  // freopen("output.in", "wt", stdout);
#endif
}

int const N = 2e5 + 9, OO = 1e9;

int arr[N];
vector<vector<int>> vec(N);

int main() {
  cout << fixed << setprecision(12);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  debug();
  int n, a, b;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a >> b;
    arr[i] = b;
    if(a == -1)
      continue;
    vec[a].push_back(b);
  }
  bool f = 0, s = 0;
  for (int i = 1; i <= n; ++i) {
    f = 0;
    if(!arr[i])
      continue;
    for(auto it: vec[i]) {
      if(!it) {
        f = 1;
        break;
      }
    }
    if(!f) {
      cout << i << " ";
      s = 1;
    }
  }
  if(!s)
    cout << -1;
  return 0;
}
