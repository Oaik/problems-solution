#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define all(v)    ((v).begin()),((v).end())
#define clr(a,b)  memset(a,b,sizeof(a))
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);
// freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int const N = 2e5 + 9, OO = 1e9;

int arr[509][509], mem[509][1024];
vector<int> ans;

int n, m;
int dp(int x, int val) {
  if (x == n) {
    if (val > 0)
      return 0;
    return -1e9;
  }
  int& ret = mem[x][val];
  if (~ret)
    return ret;
  for (int i = 0; i < m; ++i) {
    if (dp(x + 1, val ^ arr[x][i]) == 0) {
      ans.push_back(i + 1);
      ret = max(0, ret);
      return ret;
    }
  }
  ret = -1e9;
  return ret;
}

int main() {
  debug();
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      cin >> arr[i][j];
  }
  int val;
  bool c = 1;
  clr(mem, -1);
  val = dp(0, 0);
  if (val >= 0) {
    cout << "TAK\n";
    c = 0;
    reverse(all(ans));
  }
  if (c)
    cout << "NIE";
  else
    for (auto it : ans)
      cout << it << " ";
  return 0;
}
