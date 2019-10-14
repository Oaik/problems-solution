#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  // freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int const N = 1e5 + 9, OO = 1e9;

string arr[N];
int W[N], n;
ll mem[N][3];

ll dp(string prv, int i, bool rev) {
  if(i == n)
    return 0;
  ll& ret = mem[i][rev];
  if(~ret)
    return ret;

  ret = 2e18;
  string str = arr[i];
  reverse(all(str));

  if(prv <= arr[i])
    ret = min(ret, dp(arr[i], i + 1, 0));
  if(prv <= str)
    ret = min(ret, dp(str, i+1, 1) + W[i]);

  return ret;
}

int main() {
  debug();
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> W[i];
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  clr(mem, -1);
  ll ans = dp(arr[0], 1, 0);
  string strr = arr[0];
  reverse(all(strr));
  ll ans1 = dp(strr, 1, 1) + W[0];
  ll res = min(ans, ans1);
  cout << ((res >= 2e18) ? (-1) : (res));
}
