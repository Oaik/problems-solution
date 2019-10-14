#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout << fixed << setprecision(0)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, OO = 1e9, v = 1e6;
vector<string> vec;
int main() {
  fastIO;
//  freopen("input.in", "rt", stdin);  // freopen("output.in", "wt", stdout);
  string str, ss;
  cin >> str;
  int n, m;
  cin >> n, m = str.size();
  for (int i = 0; i < n; ++i) {
    cin >> ss;
    vec.push_back(ss);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    char fs = vec[i][0], sc = vec[i][1];
    int cntF = 0, cntS = 0;
    bool countMe = 0;
    for (int j = 0; j < m; ++j) {
      countMe = 0;
      if(fs == str[j])
        ++cntF, countMe = 1;
      if(sc == str[j])
        ++cntS, countMe = 1;
      if(!countMe)
        cntF = 0, cntS = 0;
      if(cntF && cntS)
        --cntF, --cntS, ++ans;
    }
  }
  cout << ans;
  return 0;
}
