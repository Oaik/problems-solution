#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 5e4 + 9, M = 4e4 + 9, OO = 1e9;

int arr[26];

int main() {
  fastIO;
  // freopen("input.in", "rt", stdin);//  freopen("output.in", "wt", stdout);
  int t;
  string s, tt, p;
  cin >> t;
  while(t--) {
    cin >> s >> tt >> p;
    clr(arr, 0);
    for (int i = 0; i < (int)p.size(); ++i)
      ++arr[p[i] - 'a'];
    int ptr1 = 0, ptr2 = 0, end1 = s.size(), end2 = tt.size();
    bool can = 1;
    while(ptr2 < end2) {
      if(ptr1 == end1) {
        if(arr[tt[ptr2] - 'a'])
          --arr[tt[ptr2] - 'a'];
        else {
          can = 0;
          break;
        }
        ++ptr2;
      } else {
        if(s[ptr1] != tt[ptr2]) {
          if(arr[tt[ptr2] - 'a'])
            --arr[tt[ptr2] - 'a'];
          else {
            can = 0;
            break;
          }
        } else
          ++ptr1;
        ++ptr2;
      }
    }
    if(!can)
      cout << "NO\n";
    else if(ptr1 == end1 && ptr2 == end2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
