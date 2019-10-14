#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, M = 2e5 + 2, OO = 1e9 + 9, MOD = 1e9 + 7;
const ll inf = 1e18;

ll arr[4 * N], tree[4 * N], lazy[4 * N];

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

void change(int node, int start, int end, int l, int r, int val) {
  if(lazy[node] != 0) {
//    tree[node] += (ll)(end - start + 1) * lazy[node];
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
//    tree[node] += (ll)(end - start + 1) * (ll)val;
    tree[node] += val;
    if(start != end) {
      lazy[node * 2] += val;
      lazy[node * 2 + 1] += val;
    }
    return;
  }
  int mid = (start + end) / 2;
  change(node * 2, start, mid, l, r, val);
  change(node * 2 + 1, mid + 1, end, l, r, val);
  tree[node] = min(tree[node * 2] , tree[node * 2 + 1]);
}

ll query(int node, int start, int end, int l, int r) {
  if(lazy[node] != 0) {
//    tree[node] += (ll)(end - start + 1) * lazy[node];
    tree[node] += lazy[node];
    if(start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if(start > r || end < l || start > end)
    return inf;
  if(start >= l && end <= r)
    return tree[node];
  int mid = (start + end) / 2;
  ll p1 = query(node * 2, start, mid, l, r);
  ll p2 = query(node * 2 + 1, mid + 1, end, l , r);
  return min(p1 , p2);
}

int main() {
  fastIO
  int n, q;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
  build(1, 1, n);
  cin >> q;
  string str;
  cin.ignore();
  for (int i = 0; i < q; ++i) {
    getline(cin, str);
    stringstream ss(str);
    str.clear();
    int u, v, c = OO, cnt = 0;
    while(ss >> str) {
      if(cnt == 0)
        u = stoi(str);
      else if(cnt == 1)
        v = stoi(str);
      else
        c = stoi(str);
      ++cnt;
    }
//    cerr << u << ' ' << v << ' ' << c << endl;
    ++u, ++v;
    if(c != OO) {
      if(v < u) {
        change(1, 1, n, u, n, c);
        change(1, 1, n, 1, v, c);
      } else {
        change(1, 1, n, u, v, c);
      }
    } else {
      if(v < u) {
        ll c1 = query(1, 1, n, u, n);
        ll c2 = query(1, 1, n, 1, v);
        cout << min(c1, c2) << '\n';
      } else {
        cout << query(1, 1, n, u, v) << '\n';
      }
    }
  }
  return 0;
}
