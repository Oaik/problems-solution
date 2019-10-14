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

set<pair<int, pair<int, int>>> setA;
set<pair<int, int>> setB;

int main() {
  fastIO
  int n, a, prv = -1, cnt = 1, idx = 1;
  cin >> n;
  cin >> a;
  prv = a;
  for (int i = 1; i < n; ++i) {
    cin >> a;
    if(a == prv)
      ++cnt;
    else {
      setA.insert({idx, {prv, cnt}});
      setB.insert({-cnt, idx});
      cnt = 1, ++idx;
    }
    prv = a;
  }
  setA.insert({idx, {prv, cnt}});
  setB.insert({-cnt, idx});
  cnt = 0;
  while(!setB.empty()) {
    auto takeIt = setB.begin();
    auto it = setA.lower_bound({(*takeIt).second, {0, -OO}});
    if(it == setA.begin() || it == setA.end()) {
      setA.erase(it);
      setB.erase(takeIt);
    } else {
//      auto it1 = setA.upper_bound({takeIt.second, {(*it).second.first, (*it).second.second}});
//      auto it2 = setA.lower_bound({takeIt.second, {(*it).second.first, (*it).second.second}});
      auto it1 = it, it2 = it;
      --it2;
      ++it1;

      int idx = min((*it1).first,(*it2).first);
      int total = (*it1).second.second + (*it2).second.second;
      int num1 = (*it1).second.first, num2 = (*it2).second.first;

      if(num1 == num2) {
        auto itt1 = setB.find({-(*it1).second.second, (*it1).first});
        auto itt2 = setB.find({-(*it2).second.second, (*it2).first});

        setB.erase(itt1);
        setB.erase(itt2);
        setB.insert({-total, idx});

        setA.erase(it1);
        setA.erase(it2);
        setA.insert({idx, {num1, total}});
      }

      setA.erase(it);
      setB.erase(takeIt);
    }
    ++cnt;
//    cerr << cnt << endl;
  }
  cout << cnt;
  return 0;
}
