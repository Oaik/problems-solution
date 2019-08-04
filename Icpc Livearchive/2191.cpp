#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9;

ll arr[N], tree[4*N];

void build(int start, int end, int node) {
  if(start == end) {
    tree[node] = arr[start];
    return;
  }
  int mid = (start + end) / 2;
  build(start, mid, 2 * node);
  build(mid+1, end, 2 * node + 1);
  tree[node] = tree[2*node] + tree[2*node + 1];
}

void change(int start, int end, int node, int idx, int val) {
  if(start == end) {
    arr[idx] = val;
    tree[node] = val;
    return;
  }
  int mid = (start + end) / 2;
  if(idx >= start && idx <= mid)
    change(start, mid, node * 2, idx, val);
  else
    change(mid + 1, end, node * 2 + 1, idx, val);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int start, int end,int node, int l, int r) {
  if(start > r || end < l) { // out
    return 0;
  }
  if(start >= l && end <= r) { // all in
    return tree[node];
  }
  int mid = (start + end) / 2;
  ll p1 = query(start, mid, node * 2, l, r);
  ll p2 = query(mid + 1, end, node * 2 + 1, l , r);
  return p1 + p2;
}


int main() {
  fastIO;
//  read;
//  write;
  int n, c = 0;
  while(cin >> n, n) {
    if(c)
      cout << '\n';
    cout << "Case " << ++c << ':' << '\n';
    for (int i = 1; i <= n; ++i)
      cin >> arr[i];
    build(1, n, 1);
    string str;
    int u, v;
    while(cin >> str, str != "END") {
      cin >> u >> v;
      if(str == "M") {
        ll sum = query(1, n, 1, u, v);
        cout << sum << '\n';
      } else {
        change(1, n, 1, u, v);
      }
    }
  }
  return 0;
}

