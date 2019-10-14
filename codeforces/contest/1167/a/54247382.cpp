#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
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
const int N = 1e5 + 9, OO = 1e9;

int main() {
  debug();
  int t;
  cin >> t;
  int n, m;
  string str;
  while(t--) {
    cin >> n >> str;
    if(n < 11) {
      cout << "NO\n";
      continue;
    } else {
      m = n - 11;
      bool can = 0;
      for (int i = 0; i <= m && !can; ++i) {
         if(str[i] == '8')
           can = 1;
      }
      if(can) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}
