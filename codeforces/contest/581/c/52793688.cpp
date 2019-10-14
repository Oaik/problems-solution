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

int const N = 2e9 + 9, OO = 1e9;

map<int, int> mp;

int main() {
  debug();
  int n, k, a;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    ++mp[a];
  }
  bool lessa = 1, la = 0;
  while (k != 0 && lessa) {
    la = 0;
    for (int i = 9; i >= 0 && lessa; --i) {
      for (int j = i; j < 100; j += 10) {
        if (mp.count(j) && mp[j]) {
          if (10 - i > k) {
            lessa = 0;
            break;
          }
          k -= 10 - i;
          --mp[j];
          ++mp[j + (10 - i)];
          la = 1;
          break;
        }
      }
      if(la)
        break;
    }
    if(!la)
      break;
  }
  int total = 0;
  for(auto it: mp) {
    total += it.second * ((it.first) / 10);
  }
  cout << total;
  return 0;
}
