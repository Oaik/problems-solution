#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 4e5 + 9, M = 1e5 + 9, OO = 1e9 + 9, MOD = 1e9 + 7;

int tree[N], lazy[N];

void change(int node, int start, int end, int l, int r) {
  if(lazy[node] != 0) {
    if(lazy[node] & 1) {
      tree[node] = (end - start + 1) - tree[node];
      if(start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
      }
    }
    lazy[node] = 0;
  }
  if(start > r || end < l || start > end)
    return;
  if(start >= l && end <= r) {
    tree[node] = (end - start + 1) - tree[node];
    if(start != end) {
      lazy[node * 2] += 1;
      lazy[node * 2 + 1] += 1;
    }
    return;
  }
  int mid = (start + end) / 2;
  change(node * 2, start, mid, l, r);
  change(node * 2 + 1, mid + 1, end, l, r);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int start, int end, int l, int r) {
  if(lazy[node] != 0) {
    if(lazy[node] & 1) {
      tree[node] = (end - start + 1) - tree[node];
      if(start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
      }
    }
    lazy[node] = 0;
  }
  if(start > r || end < l || start > end)
    return 0;
  if(start >= l && end <= r)
    return tree[node];
  int mid = (start + end) / 2;
  int p1 = query(node * 2, start, mid, l, r);
  int p2 = query(node * 2 + 1, mid + 1, end, l, r);
  return (p1 + p2);
}

int main() {
  fastIO;
  int n, m;
  cin >> n >> m;
  int t, u, v;
  for (int i = 0; i < m; ++i) {
    cin >> t >> u >> v;
    if(t == 1) {
      cout << query(1, 1, n, u, v) << '\n';
    } else {
      change(1, 1, n, u, v);
    }
  }
  return 0;
}

