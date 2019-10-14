#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, M = 2e5 + 2, OO = 1e9 + 9, MOD = 1e9 + 7;

int main() {
  fastIO
  string str;
  cin >> str;
  int e = str.find('e');
  int dot = str.find('.');
  int num = stoi(str.substr(e+1));
  string ans;
  bool min = 0;
  for (int i = 0; i < e; ++i) {
    if(i == dot) {
      min = 1;
      continue;
    }
    if(min) {
      if(num)
        --num;
      else {
        min = 0;
        ans.push_back('.');
      }
    }
    ans.push_back(str[i]);
  }
  for (int i = 0; i < num; ++i)
    ans.push_back('0');
  int it = ans.find('.');
  if((it == ans.npos) || it == -1){
    cout << ans;
    return 0;
  }
  else {
    while(!ans.empty()) {
      if(ans.back() == '0') {
        ans.pop_back();
      } else {
        break;
      }
    }
  }
  if(ans.back() == '.')
    ans.pop_back();
  cout << ans;
  return 0;
}
