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
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, OO = 1e9;

vector<pair<int, int>> vec;

bool valid(pair<int, int> ii, int idx) {
  int num = 1;
  for(auto it: vec) {
    if(abs(num - idx) > abs(ii.first - it.first) + abs(ii.second - it.second))
      return 0;
    ++num;
  }
  return 1;
}

int main() {
  debug();
  int n;
  pair<int, int> cur = {1, 1};
  cin >> n;
  if(n == 1) {
    cout << 1 << endl;
    cout << "1 1";
    return 0;
  }
  int m = n / 2;
  while (1) {
    vec.clear();
    int i = 2;
    bool can = 1;
    vec.push_back( { 1, 1 });
    cur = {1, 1};
    for (; i <= n; ++i) {
      while(!valid(cur, i)) {
        if(cur.second == m) {
          ++cur.first;
          cur.second = 1;
        } else {
          ++cur.second;
        }
        if(cur.first > m) {
          can = 0;
          break;
        }
      }
      vec.push_back(cur);
    }
    if(i == n+1 && can)
      break;
    ++m;
  }
  cout << m << '\n';
  for(auto it: vec) {
    cout << it.first << ' ' << it.second << '\n';
  }
  return 0;
}
