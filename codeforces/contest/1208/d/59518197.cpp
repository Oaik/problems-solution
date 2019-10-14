#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, M = 3e3 + 9, OO = 1e9 + 9, MOD = 1e9 + 7;

pair<ll, ll> tree[4 * N];
ll lazy[4 * N], arr[N];

void build(int node, int l, int r) {
  if(l == r) {
    tree[node] = {arr[l], -l};
    return;
  }
  int mid = (l + r) / 2;
  build(node * 2, l, mid);
  build(node * 2 + 1, mid + 1, r);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

void change(int node, int start, int end, int l, int r, ll val) {
  if(lazy[node] != 0) {
    tree[node].first -= lazy[node];
    if(start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if(start > r || end < l || start > end)
    return;
  if(start >= l && end <= r) {
    tree[node].first -= val;
    if(start != end) {
      lazy[node * 2] += val;
      lazy[node * 2 + 1] += val;
    }
    return;
  }
  int mid = (start + end) / 2;
  change(node * 2, start, mid, l, r, val);
  change(node * 2 + 1, mid + 1, end, l, r, val);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
pair<ll, ll> query(int node, int start, int end, int l, int r) {
  if(lazy[node] != 0) {
    tree[node].first -= lazy[node];
    if(start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if(start > r || end < l || start > end)
    return {1e17, 1e17};
  if(start >= l && end <= r)
    return tree[node];
  int mid = (start + end) / 2;
  pair<ll, ll> p1 = query(node * 2, start, mid, l , r);
  pair<ll, ll> p2 = query(node * 2 + 1, mid + 1, end, l , r);
  return min(p1 , p2);
}

int ans[N];

int main() {
  fastIO;
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
  build(1, 1, n);
  for (int i = 1; i <= n; ++i) {
    ll q = query(1, 1, n, 1, n).second * -1;
    ans[q] = i;
    change(1, 1, n, q + 1, n, i);
    change(1, 1, n, q, q, -1e17);
  }
  for (int i = 1; i <= n; ++i)
    cout << ans[i] << ' ';
  return 0;
}
