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
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e6 + 9, OO = 1e9;

int main() {
  debug();
  int n;
  ll total = 0;
  cin >> n;
  while(1) {
    total = 0;
    string str = to_string(n);
    for(auto c: str)
      total += (c - '0');
    if(total % 4 == 0) {
      cout << str;
      return 0;
    }
    ++n;
  }
}
