#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8, pi = acos(-1);
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  //	freopen("output.in", "wt", stdout);
#endif
}

int const N = 1e3 + 9, OO = 1e9;

bool arr[N];
int mem[N][N];

int dp(int start, int end) {
  if(start == end)
    return 0;
  int& ret = mem[start][end];
  if(ret != -1)
    return ret;
  ret = OO;
  int i;
  for (i = start; i < end; ++i) {
    if(arr[i]) {
      ret = min(ret, dp(start, i) + dp(i+1, end) + (end-start + 1));
    }
  }

  if(ret >= OO)
    return ret = 0;
  return ret;
}

int main() {
  cout << fixed << setprecision(12);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  debug();
  int n, l, a;
  while (cin >> l, l) {
    clr(mem, -1);
    clr(arr, 0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a;
      arr[a] = 1;
    }
    cout << "The minimum cutting is ";
    cout << dp(1, l) << ".\n";
  }
  return 0;
}

