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

int arr[N], tree[N], lazy[N];
bool prime[M];

void sieve() {
  int mx = 1e6 + 9;
  fill(prime, prime + M, 1);
  prime[0] = prime[1] = 0;
  for (ll i = 2; i * i <= mx; ++i) {
    if(!prime[i])
      continue;
    for (int j = i * i; j <= mx; j += i)
      prime[j] = 0;
  }
}

void build(int node, int l, int r) {
  if(l == r) {
    tree[node] = prime[arr[l]];
    return;
  }
  int mid = (l + r) / 2;
  build(node * 2, l, mid);
  build(node * 2 + 1, mid + 1, r);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void change(int node, int start, int end, int l, int r, bool inc) {
  if(lazy[node] != -1) {
    if(lazy[node] == 0)
      tree[node] = 0;
    else
      tree[node] = end - start + 1;
    if(start != end)
      lazy[node * 2] = lazy[node], lazy[node * 2 + 1] = lazy[node];
    lazy[node] = -1;
  }
  if(start > r || end < l)
    return;
  if(start >= l && end <= r) {
    if(inc)
      tree[node] = end - start + 1;
    else
      tree[node] = 0;
    if(start != end)
      lazy[node * 2] = lazy[node * 2 + 1] = inc;
    return;
  }
  int mid = (start + end) / 2;
  change(node * 2, start, mid, l, r, inc);
  change(node * 2 + 1, mid + 1, end, l, r, inc);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int start, int end, int l, int r) {
  if(lazy[node] != -1) {
    if(lazy[node] == 0)
      tree[node] = 0;
    else
      tree[node] = end - start + 1;
    if(start != end)
      lazy[node * 2] = lazy[node], lazy[node * 2 + 1] = lazy[node];
    lazy[node] = -1;
  }
  if(start > r || end < l)
    return 0;
  if(start >= l && end <= r)
    return tree[node];
  int mid = (start + end) / 2;
  ll p1 = query(node * 2, start, mid, l, r);
  ll p2 = query(node * 2 + 1, mid + 1, end, l, r);
  return (p1 + p2);
}

int main() {
  fastIO;
  int t;
  cin >> t;
  sieve();
  for (int i = 1; i <= t; ++i) {
    cout << "Case " << i << ":\n";
    int n, q;
    clr(tree, 0);
    clr(lazy, -1);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
      cin >> arr[i];
    build(1, 1, n);
    int u, v, type, pp;
    while(q--) {
      cin >> type >> u >> v;
      if(type == 1) {
        cout << query(1, 1, n, u, v) << '\n';
      } else {
        cin >> pp;
        change(1, 1, n, u, v, prime[pp]);
      }
    }
  }
  return 0;
}

