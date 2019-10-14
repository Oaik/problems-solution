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

int const N = 3e5 + 9, OO = 1e9;

char arr[109][109];
int dx[ ] = {1, -1, 0, 0 }, dd[ ] = { 0, 0, 1, -1 }, vis[109][109];
vector<pair<int, int>> vec;
  int n, m;
bool valid(int x, int xx) {
  return x >= 0 && x < n && xx >=0 && xx < m;
}

int main() {
  debug();
  //  { } [ ] t
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
      if(arr[i][j] == 'W')
        vec.push_back({i, j });
    }
  }
  int icn = 0;
  for(auto ii: vec) {
    for (int i = 0; i < 4; ++i) {
      if(valid(ii.first + dx[i], ii.second + dd[i]) && !vis[ii.first + dx[i] ][ ii.second + dd[i]] && arr[ii.first + dx[i] ][ ii.second + dd[i]] == 'P') {
        vis[ii.first + dx[i] ][ ii.second + dd[i]] = 1, ++icn;
        break;
      }
    }
  }
  cout << icn;
}
