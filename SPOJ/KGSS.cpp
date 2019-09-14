#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 3e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

int arr[N], tree[4 * N];

void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = arr[start];
    return;
  }
  int mid = (start + end) / 2;
  build(node * 2, start, mid);
  build(node * 2 + 1, mid + 1, end);
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

void update(int node, int start, int end, int idx, int val) {
  if (start == end && start == idx) {
    arr[idx] = val;
    tree[node] = val;
    return;
  }
  int mid = (start + end) / 2;
  if (idx > mid) {
    update(node * 2 + 1, mid + 1, end, idx, val);
  } else {
    update(node * 2, start, mid, idx, val);
  }
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int queryID(int node, int start, int end, int l, int r, int val) {
  if (tree[node] < val || start > r || end < l || start > end)
    return 0;
  if (start == end) {
    if (tree[node] != val)
      return 0;
    return start;
  }
  int mid = (start + end) / 2;
  if(tree[node * 2] >= val) {
    int p1 = queryID(node * 2, start, mid, l, r, val);
    if (p1)
      return p1;
  }
  if(tree[node * 2 + 1] >= val) {
    int p2 = queryID(node * 2 + 1, mid + 1,end, l, r, val);
    if (p2)
      return p2;
  }
  return 0;
}

int query(int node, int start, int end, int l, int r) {
  if (start > r || end < l || start > end)
    return -OO;
  if (start >= l && end <= r)
    return tree[node];
  int mid = (start + end) / 2;
  int p1 = query(node * 2, start, mid, l, r);
  int p2 = query(node * 2 + 1, mid + 1, end, l, r);
  return max(p1, p2);
}

int main() {
  fastIO
//  read
  int n,
  m;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
  build(1, 1, n);
  cin >> m;
  int u, v;
  char c;
  while (m--) {
    cin >> c >> u >> v;
    if (c == 'Q') {
      int idx1, val1, val2;
      val1 = query(1, 1, n, u, v);
      idx1 = queryID(1, 1, n,u, v, val1);
      update(1, 1, n, idx1, -OO);
      val2 = query(1, 1, n, u, v);
      cout << val1 + val2 << '\n';
      update(1, 1, n, idx1, val1);
    } else
      update(1, 1, n, u, v);
  }
  return 0;
}

