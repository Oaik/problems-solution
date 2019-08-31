#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 4e5 + 9, M = 1e6 + 19, OO = 1e9 + 9;

ll tree[N], lazy[N];

void change(int node, int start, int end, int l, int r, int val) {
  if(lazy[node] != 0) {
    tree[node] += (ll)(end - start + 1) * lazy[node];
    if(start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if(start > r || end < l)
    return;
  if(start >= l && end <= r) {
    tree[node] += (ll)(end - start + 1) * (ll)val;
    if(start != end) {
      lazy[node * 2] += val;
      lazy[node * 2 + 1] += val;
    }
    return;
  }
  int mid = (start + end) / 2;
  change(node * 2, start, mid, l, r, val);
  change(node * 2 + 1, mid + 1, end, l, r, val);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int start, int end, int l, int r) {
  if(lazy[node] != 0) {
    tree[node] += (ll)(end - start + 1) * lazy[node];
    if(start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if(start > r || end < l)
    return 0;
  if(start >= l && end <= r)
    return tree[node];
  int mid = (start + end) / 2;
  ll p1 = query(node * 2, start, mid, l, r);
  ll p2 = query(node * 2 + 1, mid + 1, end, l , r);
  return (p1 + p2);
}

int main() {
  fastIO;
  int t;
  cin >> t;
  while(t--) {
    clr(tree, 0);
    clr(lazy, 0);
    int n, m, type, u, v, c;
    cin >> n >> m;
    while(m--) {
      cin >> type >> u >> v;
      if(type == 0) {
        cin >> c;
        change(1, 1, n,u, v, c);
      } else {
        cout << query(1, 1, n,u, v) << endl;
      }
    }
  }
  return 0;
}

