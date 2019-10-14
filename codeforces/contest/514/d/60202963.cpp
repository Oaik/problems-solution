#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, M = 7, OO = 1e9 + 9, MOD = 1e9 + 7;

int en[N][M];
int tree[4*N][M];

void build(int node, int start, int end, int idx) {
  if(start == end) {
    tree[node][idx] = en[start][idx];
    return;
  }
  int mid = (start + end) / 2;
  build(node * 2, start, mid, idx);
  build(node * 2 + 1, mid + 1, end, idx);
  tree[node][idx] = max(tree[node * 2][idx], tree[node * 2 + 1][idx]);
}

int query(int node, int start, int end, int l, int r, int idx) {

  if(start > r || end < l || start > end)
    return 0;
  if(start >= l && end <= r)
    return tree[node][idx];

  int mid = (start + end) /2;
  int p1 = query(node * 2, start, mid, l, r, idx);
  int p2 = query(node * 2 + 1, mid + 1, end, l, r, idx);
  return max(p1, p2);
}

int main() {
  fastIO
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> en[i][j];
  for (int i = 1; i <= m; ++i)
    build(1, 1, n, i);
  int l = 1, r = 1, best = 0;
  vector<int> ans(m+1, 0);
  while(r <= n) {
    int cur = 0;
    for (int i = 1; i <= m; ++i)
      cur += query(1, 1, n, l, r, i);
    bool can = (cur <= k);
    // suc
    if(can) {
      if(r - l + 1 > best) {
        best = r - l + 1;
        // update ans vector
        // query from 0 to m and update with max val in ans
        for (int i = 1; i <= m; ++i)
          ans[i] = query(1, 1, n, l, r, i);
      }
      ++r;
      continue;
    }
    // err
    if(l == r)
      ++r;
    ++l;
  }
  for (int i = 1; i <= m; ++i)
    cout << ans[i] << ' ';
  return 0;
}
