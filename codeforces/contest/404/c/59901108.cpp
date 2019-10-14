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

vector<pair<int, int>> vec, ans;
vector<int> vv[N];
ll kam[N];
int kamEdge[N];

int main() {
  fastIO
  int n, k, a, zeros = 0, idx;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if(a != 0)
      vec.push_back({a, i + 1});
    else
      ++zeros, idx = i + 1;
  }
  if(zeros == 0 || zeros > 1) {
    cout << -1 << '\n';
    return 0;
  }
  vec.push_back({0, idx});
  vv[0].push_back(idx);
  kamEdge[idx] = 0;
  sort(all(vec));
  int prv = 0, curNode = -1;
  for (int i = 1; i < n; ++i) {
    int val = vec[i].first;
    if(prv != val) {
      if(!vv[val-1].empty()) {
        curNode = vv[val-1].back();
        vv[val-1].pop_back();
      } else {
        cout << -1 << '\n';
        return 0;
      }
    }
    while(kamEdge[curNode] >= k) {
      if(!vv[val-1].empty()) {
        curNode = vv[val-1].back();
        vv[val-1].pop_back();
      } else {
        cout << -1 << '\n';
        return 0;
      }
    }
    ans.push_back({curNode, vec[i].second});
    vv[val].push_back(vec[i].second);
    ++kamEdge[curNode];
    ++kamEdge[vec[i].second];
    prv = vec[i].first;
  }
  cout << ans.size() << '\n';
  for(auto it: ans)
    cout << it.first << ' ' << it.second << '\n';
  return 0;
}
