#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 5e4 + 9, M = 3e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

ll arr[N];
struct seg {
  ll left, right, total, best;
  seg() {}
};

seg tree[4*N];
seg invalidSeg;

void build(int node, int start, int end) {
  if(start == end) {
    tree[node].left = tree[node].right = tree[node].total = tree[node].best = arr[start];
    return;
  }
  int mid = (start + end) >> 1;
  build(node * 2, start, mid);
  build(node * 2 + 1, mid + 1, end);
  seg p1 = tree[node * 2], p2 = tree[node * 2 + 1], p3;
  p3.total = p1.total + p2.total;

  p3.left = max(p1.left, max(p1.total, p1.total + p2.left));
  p3.left = max(p3.left, p3.total);

  p3.right = max(p2.right, max(p2.total, p2.total + p1.right));
  p3.right = max(p3.right, p3.total);

  p3.best = max(p3.total, max(p1.right + p2.left, max(p3.left, p3.right)));
  p3.best = max(p3.best, max(p1.best, p2.best));

  tree[node] = p3;
}

seg query(int node, int start, int end, int l, int r) {
  if(start > r || end < l)
    return invalidSeg;
  if(start >= l && end <= r)
    return tree[node];
  int mid = (start + end) >> 1;
  seg p1 = query(node * 2, start, mid, l, r),
      p2 = query(node * 2 + 1, mid + 1, end, l, r);
  seg p3;
  p3.total = p1.total + p2.total;

  p3.left = max(p1.left, max(p1.total, p1.total + p2.left));
  p3.left = max(p3.left, p3.total);

  p3.right = max(p2.right, max(p2.total, p2.total + p1.right));
  p3.right = max(p3.right, p3.total);

  p3.best = max(p3.total, max(p1.right + p2.left, max(p3.left, p3.right)));
  p3.best = max(p3.best, max(p1.best, p2.best));
  return p3;
}

void update(int node, int start, int end, int l, int r) {
  if(start > r || end < l)
    return;
  if(start >= l && end <= r) {
    tree[node].left = tree[node].right = tree[node].total = tree[node].best = arr[start];
    return;
  }
  int mid = (start + end) >> 1;
  update(node * 2, start, mid, l, r);
  update(node * 2 + 1, mid + 1, end, l, r);
  seg p1 = tree[node * 2],
      p2 = tree[node * 2 + 1];
  seg p3;
  p3.total = p1.total + p2.total;

  p3.left = max(p1.left, max(p1.total, p1.total + p2.left));
  p3.left = max(p3.left, p3.total);

  p3.right = max(p2.right, max(p2.total, p2.total + p1.right));
  p3.right = max(p3.right, p3.total);

  p3.best = max(p3.total, max(p1.right + p2.left, max(p3.left, p3.right)));
  p3.best = max(p3.best, max(p1.best, p2.best));
  tree[node] = p3;
}


int main() {
  fastIO;
  int n, m, u, v;
  invalidSeg.left = invalidSeg.right = invalidSeg.total = invalidSeg.best = -OO;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
  build(1, 1, n);
  cin >> m;
  int t;
  while (m--) {
    cin >> t >> u >> v;
    if(t)
      cout << query(1, 1, n, u, v).best << '\n';
    else {
      arr[u] = v;
      update(1, 1, n, u, u);
    }
  }
  return 0;
}
