#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define all(v)    ((v).begin()),((v).end())
#define clr(a,b)  memset(a,b,sizeof(a))
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);
// freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int const N = 1e6 + 9, OO = 1e9;

bool visited[N], vis[N];
vector<vector<int>> vec(N);
vector<vector<int>> vec2(N);
int ans[N], arr[N];
int ii = 1, mx = 0, cur = 0;

void DFS(int x) {
  if (x != 0) {
    ans[ii] = x;
    ii += 2;
  }
  visited[x] = 1;
  for (auto it : vec[x]) {
    if(!visited[it])
      DFS(it);
  }
}

void DFS3(int x) {
  if (x != 0) {
    ans[ii] = x;
    ii -= 2;
  }
  visited[x] = 1;
  for (auto it : vec2[x]) {
    if(!visited[it])
      DFS3(it);
  }
}


void DFS2(int x) {
  vis[x] = 1, ++ii;
  for(auto it: vec[x]) {
    if(!vis[it] && !visited[it]) {
      cur = it;
      DFS2(it);
    }
  }
}

int main() {
  debug();
  int n, a, b;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i] >> b;
    vec[arr[i]].push_back(b);
    vec2[b].push_back(arr[i]);
  }
  DFS(0);
  ii = 0;
  for (int i = 0; i < n; ++i) {
    if(visited[arr[i]])
      continue;
    clr(vis, 0);
    ii = 0;
    DFS2(arr[i]);
    break;
  }
  ii = n - 1;
  if(!(n & 1))
    --ii;
  DFS3(cur);
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  return 0;
}
