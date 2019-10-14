#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 1e2 + 9, OO = 1e9;

unordered_map<string, bool> mp;
queue<string> q;

int main() {
  fastIO;
//  read;
  int n;
  string str, repAns;
  cin >> n >> str;
  repAns = str;
  q.push(str);
  while(!q.empty()) {
    string tp = q.front();
    q.pop();
    if(mp[tp])
      continue;
    mp[tp] = 1;
    if(tp < repAns)
      repAns = tp;
    // shift
//    for (int k = 0; k < n; ++k) {
      string res;
      for (int i = n-0-1; i < n; ++i)
        res += tp[i];
      for (int i = 0; i < n-0-1; ++i)
        res += tp[i];
      if(!mp[res])
        q.push(res);
//    }
   // add one
//    for (int k = 0; k < 9; ++k) {
      for (int i = 0; i < n; ++i)
        if(tp[i] == '9')
          tp[i] = '0';
        else
          tp[i] = (char)(tp[i] + 1);
      if(!mp[tp])
        q.push(tp);
//    }
  }
  cout << repAns;
  return 0;
}
