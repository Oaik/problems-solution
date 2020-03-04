#include<bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define ll long long
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 1e5 + 9, M = 5e2 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

vector<int> adj[N];
int mxLen, node;

void dfs(int x, int par, int dep) {
  if(dep > mxLen) {
    mxLen = dep;
    node = x;
  }
  for(int it: adj[x]) {
    if(par == it) continue;
    dfs(it, x, dep + 1);
  }
}

set<int> worse, best1, best2;

void bfs(int x, bool meen) {
  queue<pair<int, int>> qq;
  qq.push({x, -1});
  vector<int> last;
  int lvl = 0;
  while(!qq.empty()) {
    int sz = qq.size();
    vector<int> cur;
    ++lvl;
    while(sz--) {
      auto tp = qq.front();
      qq.pop();
      for(int it: adj[tp.first]) {
        if(it == tp.second) continue;
        if(lvl == mxLen/2 || ( (mxLen&1) && (lvl - 1 == mxLen / 2))) {
          if(meen)
            best1.insert(it);
          else
            best2.insert(it);
        }
        qq.push({it, tp.first});
        cur.push_back(it);
      }
    }
    if(qq.empty())
      break;
    last = cur;
  }
  for(int it: last)
    worse.insert(it);
}

int main() {
  fastIO;
#ifdef LOCAL
  freopen("input.in", "rt", stdin);
#endif
  int n, k, a;
  while(cin >> n) {
    for (int i = 1; i <= n; ++i) {
      cin >> k;
      for (int j = 0; j < k; ++j) {
        cin >> a;
        adj[i].push_back(a);
      }
    }
    mxLen = 0;
    dfs(1, -1, 0);
    mxLen = 0;
    int from = node;
    dfs(from, -1, 0);
    int to = node;

    bfs(from, 0);
    bfs(to, 1);
    set<int> best;
    for(auto it: best1)
      if(best2.find(it) != best2.end() && worse.find(it) == worse.end())
        best.insert(it);

    vector<int> bestV = vector<int>(best.begin(), best.end());
    cout << "Best Roots  : ";
    for (int i = 0; i < (int)bestV.size(); ++i)
      cout << bestV[i] << " \n"[i+1 == (int)bestV.size()];

    vector<int> worseV = vector<int>(worse.begin(), worse.end());
    cout << "Worst Roots : ";
    for (int i = 0; i < (int)worseV.size(); ++i)
      cout << worseV[i] << " \n"[i+1 == (int)worseV.size()];

    for (int i = 1; i <= n; ++i)
      adj[i].clear();
    best1.clear(), best2.clear(), worse.clear();
  }
  return 0;
}

