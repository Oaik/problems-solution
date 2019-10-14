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
  cout << fixed << setprecision(12);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, OO = 1e9;

int main() {
  debug();
  int t;
  cin >> t;
  string str1, str2;
  while(t--) {
    cin >> str1 >> str2;
    bool can = 0;
    int ptr1 = 0, ptr2 = 0;
    while(ptr1 < str1.size() || ptr2 < str2.size()) {
      if(ptr1 < str1.size() && str1[ptr1] == str2[ptr2]) {
        ++ptr1, ++ptr2;
      } else {
        if(str2[ptr2] == str1[ptr1 - 1]) {
          ++ptr2;
        } else
          can = 1;
      }
      if(can)
        break;
    }
    if(can)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}