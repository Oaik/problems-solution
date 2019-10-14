#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 3e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

vector<int> vecA, vecB;

int main() {
  fastIO;
  int n, m = 0;
  cin >> n;
  string str1, str2;
  cin >> str1 >> str2;
  for (int i = 0; i < n; ++i) {
    if(str1[i] != str2[i]) {
      if(str1[i] == 'a')
        vecA.push_back(i + 1);
      else
        vecB.push_back(i + 1);
      ++m;
    }
  }
  if(m & 1) {
    cout << -1;
    return 0;
  }
  vector<pair<int, int>> ans;
  int nnn = vecA.size();
  while(!vecA.empty() || !vecB.empty()) {
    while(!vecA.empty()) {
      int num = vecA.back();
      vecA.pop_back();
      if(vecA.empty()) {
        ans.push_back({num , num});
        vecB.push_back(num);
      } else {
        int num2 = vecA.back();
        vecA.pop_back();
        ans.push_back({num, num2});
      }
    }
    while(!vecB.empty()) {
      int num = vecB.back();
      vecB.pop_back();
      if(vecB.empty()) {
        ans.push_back({num, num});
        vecA.push_back(num);
      } else {
        int num2 = vecB.back();
        vecB.pop_back();
        ans.push_back({num, num2});
      }
    }
  }
  cout << ans.size() << '\n';
  for(auto it: ans)
    cout << it.first << ' ' << it.second << '\n';
  return 0;
}
