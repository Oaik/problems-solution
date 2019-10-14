#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
const int M = 2e5 + 9;

int m;
int main() {
  fastIO;
  cin >> m;
  string ss;
  cin >> ss;
  int ans = 0;
  for (int i = 0; i < m; i += 2) {
    if(ss[i] == ss[i+1]) {
      ++ans;
      if(ss[i+1] == 'a')
        ss[i+1] = 'b';
      else
        ss[i+1] = 'a';
    }
  }
  cout << ans;
  cout << '\n';
  cout << ss;
  return 0;
}

