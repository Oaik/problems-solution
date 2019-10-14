
 #include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)    ((v).begin()),((v).end())
#define sz(x)     ((ll) (x).size())
#define clr(a,b)  memset(a,b,sizeof(a))
const double EPS = 1e-8;
const double pi = acos(-1);
ll dcmp(double a, double b) {
  return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);
  //freopen("output.in", "wt", stdout);
#endif
}

int const N = 1e5 + 9, M = 100 + 9, OO = 5e8 + 9;
int n, m, start, l, k, t, u, v, c;

vector<pair<int, pair<ll, int>>> vec[N];
bool vis[N];
int level = 0, sz = 0, par, cur, child;
ll mxVal = 0;

ll BFS(int start) {
  queue<int> q;
  q.push(start);
  level = 0, sz = q.size(), par, cur, child;
  mxVal = 0;
  while(level < l) {
    sz = q.size();
    if(!sz)
      return mxVal;
    while(sz--) {
      cur = q.front();
      q.pop();
      par = sz(vec[cur]);
      for (int i = 0; i < par; ++i) {
        child = vec[cur][i].first;
        int iddx = vec[cur][i].second.second;
        if(!vis[iddx]) {
          mxVal = max(mxVal, vec[cur][i].second.first);
          vis[iddx] = 1;
          q.push(child);
        }
      }
    }
    ++level;
    if(level == k)
      return mxVal;
  }
  return -1;
}

int main() {
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//  debug();
  freopen("path.in", "rt", stdin);
  cin >> t;
  while (t--) {
    cin >> n >> m >> start >> l >> k;
    for (int i = 0; i < m; ++i) {
      cin >> u >> v >> c;
      --u, --v;
      vec[u].push_back( { v, {c, i} });
      vec[v].push_back( { u, {c, i} });
    }
    --start;
    cout << BFS(start) << "\n";
    int clearYabnyS7 = max(n, m);
    for (int i = 0; i <= clearYabnyS7; ++i)
      vec[i].clear(), vis[i] = 0;
  }
  return 0;
}
