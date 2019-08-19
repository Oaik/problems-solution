#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e6 + 9, OO = 1e9;

map<pair<int, int>, bool> mp;

int BFS(int a, int b, int c) {
  queue<pair<int, int>> q;
  q.push({0, 0});
  int depth = 1;
  int sz = q.size();
  int x, y;
  while(!q.empty()) {
    sz = q.size();
    pair<int, int> it;
    while(sz--) {
      it = q.front();
      q.pop();
      mp[it] = 1;
      if(!mp[{0, it.second}]) { // empty
        if(0 == c || it.second == c) {
          return depth;
        }
        q.push({0, it.second});
      }
      if(!mp[{it.first, 0}]) { // empty
        if(it.first == c || 0 == c) {
          return depth;
        }
        q.push({it.first, 0});
      }
      if(!mp[{a, it.second}]) { // fill
        if(a == c || it.second == c) {
          return depth;
        }
        q.push({a, it.second});
      }
      if(!mp[{it.first, b}])  { // fill
        if(it.first == c || b == c) {
          return depth;
        }
        q.push({it.first, b});
      }
      x = min(a, it.first + it.second);
      y = min(b, it.first + it.second);
      if(!mp[{it.first + it.second - y, y}]) { // a -> b
        if(it.first + it.second - y == c || y == c) {
          return depth;
        }
        q.push({it.first + it.second - y, y});
      }
      if(!mp[{x, it.first + it.second - x}]) { // b -> a
        if(it.first + it.second - x == c || x == c) {
          return depth;
        }
        q.push({x, it.first + it.second - x});
      }
    }
    ++depth;
  }
  return -1;
}

int main() {
  fastIO;
  int t;
  cin >> t;
  while(t--) {
    mp.clear();
    int a, b, c;
    cin >> a >> b >> c;
    if(a < b)
      swap(a, b);
    if(a < c) {
      cout << "-1\n";
      continue;
    }
    cout << BFS(a, b, c) << '\n';
  }
  return 0;
}

