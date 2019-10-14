#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 3e5 + 9, OO = 1e9;

vector<vector<pair<int, pair<int, int>>>> vec(N);
int arr[N];

int main() {
  fastIO;
  int n, m, u, v, c;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> c;
    vec[u].push_back({m-i, {v, c}});
  }
  vector<pair<int, pair<int, int>>> vv;
  priority_queue<pair<int, pair<int, int>>> qq;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < (int)vec[i].size(); ++j) {
      qq.push(vec[i][j]);
    }
    if(qq.empty()) continue;
    auto tp = qq.top();
    if(qq.empty())
      continue;
    auto tpp = qq.top();
    if(tp.second.second == i) {
      if((int)qq.size() == 1)
        continue;
      qq.pop();
      tpp = qq.top();
      while((tpp.second.first < i) || tpp.second.second == i) {
        if(qq.empty())
          break;
        qq.pop();
        if(tpp.second.second == i) {
          vv.push_back(tpp);
          tpp.second.first = i - 1;
        }
        if(!qq.empty())  {
          tpp = qq.top();
        }
      }
      qq.push(tp);
      tp = tpp;
    }
    if(!vv.empty()) {
      for(auto it: vv)
        qq.push(it);
      vv.clear();
    }
    if(tp.second.first >= i)
      arr[i] = tpp.second.second;
    while(!qq.empty() && (qq.top().second.first <= i))
      qq.pop();
  }
  for (int i = 1; i <= n; ++i) {
    cout << arr[i] << ' ';
  }
}
