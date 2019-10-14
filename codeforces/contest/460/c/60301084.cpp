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
const unsigned ll inf = 9e18;

int arr[N], tree[4*N], lazy[4*N];

void build(int node, int start, int end) {
  if(start == end) {
    tree[node] = arr[start];
    return;
  }
  int mid = (start + end) / 2;
  build(node * 2, start, mid);
  build(node * 2 + 1, mid + 1, end);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int queryID(int node, int start, int end, int val) {
  if(lazy[node]) {
    tree[node] += lazy[node];
    if(start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if(start == end) {
    if(tree[node] == val)
      return start;
    return OO;
  }
  if(tree[node] > val)
    return OO;
  int mid = (start + end) / 2;
  int p1 = queryID(node * 2, start, mid, val);
  if(p1 != OO)
    return p1;
  int p2 = queryID(node * 2 + 1, mid + 1, end, val);
  return p2;
}

void update(int node, int start, int end, int l, int r) {
  if(lazy[node]) {
    tree[node] += lazy[node];
    if(start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if(start > r || end < l)
    return;
  if(start >= l && end <= r) {
    tree[node]++;
    if(start != end) {
      ++lazy[node * 2];
      ++lazy[node * 2 + 1];
    }
    return;
  }

  int mid = (start + end) / 2;
  update(node * 2, start, mid, l, r);
  update(node * 2 + 1, mid + 1, end, l, r);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int main() {
  fastIO
  int n,
  m, w;
  cin >> n >> m >> w;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
  build(1, 1, n);
  while(m--) {
    int idx = queryID(1, 1, n, tree[1]);
    update(1, 1, n, idx, min(idx + w - 1, n));
  }
  cout << tree[1] << endl;
  return 0;
}
