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

int const N = 1e9 + 9, OO = 1e9;

int main() {
  debug();
  ll a, b, c, tempa, tempb, tempc;
  cin >> a >> b >> c;
  ll nW = 0, d = 0, total = 0;
  while(a > 2 && b > 1 && c > 1) {
    ++nW;
    a -= 3, b-= 2, c -= 2;
  }
  tempa = a, tempb = b, tempc = c;
  for (int i = 0; i < 7; ++i) {
    int j = i;
    d = 0;
    a = tempa, b = tempb, c = tempc;
    while(1) {
      if( (j % 7 == 0) || (j % 7 == 5)) {
        if(!c)
          break;
        --c;
      }
      else if((j % 7 == 1) || (j % 7 == 4)) {
        if(!b)
          break;
        --b;
      } else {
        if(!a)
          break;
        --a;
      }
      ++d, ++j;
    }
    total = max(total, d);
  }
  total += nW * 7;
  cout << total;
  return 0;
}