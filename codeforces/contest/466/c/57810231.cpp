#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
double const EPS = 1e-15, PI = acos(-1);
const int N = 5e5 + 9, OO = 1e9;
int n;
ll mem[N][4], arr[N], sum = 0;
ll DP(int x, int taken) {
  if(taken == 2)
    return 1;
  if(x == n)
    return 0;
  ll& ret = mem[x][taken];
  if(~ret)
    return ret;
  ret = 0;
  ret += DP(x+1, taken);
  if(taken == 0 && arr[x] == sum)
    ret += DP(x+1, taken + 1);
  if(taken == 1 && arr[x] == sum * 2)
    ret += DP(x+1, taken + 1);
  return ret;
}
int main() {
  fastIO;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    arr[i] += arr[i-1];
  }
  sum = arr[n];
  if(sum % 3 != 0) {
    cout << 0;
    return 0;
  }
  sum /= 3;
  clr(mem, -1);
  ll ans = DP(1, 0);
  cout << ans;
  return 0;
}
