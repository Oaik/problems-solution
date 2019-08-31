#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 4e5 + 9, OO = 1e9 + 9;

ll tree[N], lazy[N];

ll query(int node, int start, int end, int l, int r) {
  if(lazy[node] != 0) {
    tree[node] += (end - start + 1) * lazy[node];
    if(start != end) {
      lazy[node * 2]+= lazy[node];
      lazy[node * 2 + 1]+= lazy[node];
    }
    lazy[node] = 0;
  }
  if(start > r || end < l)
    return 0;
  if(start >= l && end <= r)
    return tree[node];
  int mid = (start + end) / 2;
  int p1 = query(node * 2, start, mid, l, r);
  int p2 = query(node * 2 + 1, mid + 1, end, l, r);
  return (p1 + p2);
}

void update(int node, int start, int end, int l, int r) {
  if(lazy[node] != 0) {
    tree[node] += (end - start + 1) * lazy[node];
    if(start != end) {
      lazy[node * 2]+= lazy[node];
      lazy[node * 2 + 1]+= lazy[node];
    }
    lazy[node] = 0;
  }
  if(start > end || start > r || end < l)
    return;
  if(start >= l && end <= r) {
    tree[node] += (end - start + 1);
    if(start != end) {
      lazy[node * 2]++;
      lazy[node * 2 + 1]++;
    }
    return;
  }
  int mid = (start + end) / 2;
  update(node * 2, start ,mid, l, r);
  update(node * 2 + 1, mid + 1 ,end, l, r);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
  fastIO;
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    clr(tree, 0);
    clr(lazy, 0);
    cout << "Scenario #" << i << ":\n";
    int n, q;
    string str;
    cin >> n >> q;
    while(q--) {
      int u, v;
      cin >> str >> u >> v;
      if(str == "answer") {
        cout << query(1, 1, n, u, v) << '\n';
      } else {
        cout << "OK\n";
        update(1, 1, n, u, v);
      }
    }
  }
  return 0;
}

