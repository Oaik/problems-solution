#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 2e5 + 2, OO = 1e9 + 9, MOD = 1e9 + 7;

vector<int> vec, vv;
priority_queue<int,vector<int> ,greater<int>> ev, odds;

int main() {
//  fastIO
  int n,m, a;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    if(a & 1)
      odds.push(a);
    else
      vec.push_back(a);
  }
  int ptr1 = 0, ptr2 = 0, cnt = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &a);
    if(a > 29)
      continue;
    if(a == 0) {
      if(!odds.empty()) {
        vec.push_back(odds.top() - 1);
        odds.pop();
        ++cnt;
        continue;
      }
    }
    vv.push_back((1 << a));
  }
  while(!odds.empty()) {
    vec.push_back(odds.top());
    odds.pop();
  }
  sort(all(vv));
  sort(all(vec));
  while(ptr1 < (int)vec.size() && ptr2 < (int)vv.size()) {
    if(vec[ptr1] < vv[ptr2]) {
      ++ptr1;
      continue;
    }
    vec[ptr1] -= vv[ptr2];
    ++ptr2;
    ++cnt;
  }
  printf("%d", cnt);
  return 0;
}
