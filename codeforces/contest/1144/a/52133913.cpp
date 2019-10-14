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

int const N = 1e5 + 9, OO = 1e9;

int main() {
  cout << fixed << setprecision(12);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  debug();
  int n;
  cin >> n;
  string str;
  bool f= 0;
  for (int i = 0; i < n; ++i) {
    cin >> str;
    f = 0;
    sort(all(str));
    char c = str[0];
    for (int j = 1; j < str.size(); ++j) {
      if(str[j] != c + j) {
        f = 1;
        break;
      }
    }
    if(f) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}