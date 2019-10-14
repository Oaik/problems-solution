#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9;

unordered_map<char, int> mp;
ll MOD = 1e9 + 7;

ll power(ll x, ll y) {
  ll res = 1;
  x = x % MOD;
  while(y) {
    if(y & 1)
      res = (res * x) % MOD;
    y = y >> 1;
    x = (x * x) % MOD;
  }
  return res;
}

int main() {
  fastIO;
  string str;
  int n;
  cin >> n >> str;
  for(char c: str)
    ++mp[c];
  int mx = 0, cnt = 0;
  for(auto it: mp)
    mx = max(mx, it.second);
  for(auto it:mp)
    if(it.second == mx)
      ++cnt;
  cout << power(cnt, n);
  return 0;
}
