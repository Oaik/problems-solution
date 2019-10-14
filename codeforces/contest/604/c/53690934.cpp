#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  //freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(6);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
int const N = 2e5 + 9, M = 1e5 + 9, OO = 1e9;

int main() {
  debug();
  int n;
  string str;
  int cur, prv = -1, total = 0;
  cin >> n >> str;
  if(n <= 3) {
    cout << n;
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    cur = str[i] - '0';
    if (cur != prv)
      ++total;
    prv = cur;
  }
  int st = 0;
  for (int i = 1; i < n; ++i) {
    if(str[i] == str[i-1]) {
      st = i;
      break;
    }
  }
  // if st != 0 then end != 0
//  int end = 0;
//  for (int i = n-2; i > 0; --i) {
//    if(str[i] == str[i+1]) {
//      end = i;
//      break;
//    }
//  }

//  if(st && end)
  if(st)
    total += 2;
  cout << min(total, n);
//  cout << total;
}
