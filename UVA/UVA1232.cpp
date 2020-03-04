#include<bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define ll long long
#define fastIO cout << fixed << setprecision(12), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 1e5 + 9, M = 1e2 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

pair<int, int> tree[4 * N];
int lazy[4 * N];

void propagate(int node, int start, int end) {
  if(lazy[node]) {
    tree[node].first = tree[node].second = lazy[node];
    if(start != end)
      lazy[node * 2] = lazy[node * 2 + 1] = lazy[node];
  }
  lazy[node] = 0;
}

int query(int node, int start, int end, int l, int r, int h) {
  propagate(node, start, end);
  if(start > r || end < l)
    return 0;
  if(start >= l && end <= r) {
    if(h >= tree[node].first)
      return end - start + 1;
    if(h < tree[node].second)
      return 0;
    if(start == end)
      return 0;
  }
  int mid = (start + end) / 2;
  int p1 = query(node * 2, start, mid, l, r, h);
  int p2 = query(node * 2 + 1, mid + 1, end, l, r, h);
  return p1 + p2;
}

void change(int node, int start, int end, int l, int r, int h) {
  propagate(node, start, end);
  if(start > r || end < l)
    return;
  if(start >= l && end <= r) {
    if(h >= tree[node].first) {
      lazy[node] = h;
      propagate(node, start, end);
      return;
    }
    if(h < tree[node].second)
      return;
    if(start == end)
      return;
  }
  int mid = (start + end) / 2;
  change(node * 2, start, mid, l, r, h);
  change(node * 2 + 1, mid + 1, end, l, r, h);
  tree[node].first = max(tree[node * 2].first, tree[node * 2 + 1].first);
  tree[node].second = min(tree[node * 2].second, tree[node * 2 + 1].second);
}

int main() {
  fastIO;
#ifdef LOCAL
  freopen("input.in", "rt", stdin);
#endif
  int t;
  cin >> t;
  while(t--) {
    memset(tree, 0, sizeof tree);
    memset(lazy, 0, sizeof lazy);
    int n, l, r, h;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      cin >> l >> r >> h;
      --r;
      ans += query(1, 1, N, l, r, h);
      change(1, 1, N, l, r, h);
    }
    cout << ans << '\n';
  }
  return 0;
}

