#include<bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define ll long long
#define fastIO cout << fixed << setprecision(12), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 2e5 + 9, M = 1e5 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

int arr[N], tree[4*N], ans[N];

void build(int node, int start, int end) {
  if(start == end) {
    tree[node] = 1;
    return;
  }
  int mid = (start + end) / 2;
  build(node * 2, start, mid);
  build(node * 2 + 1,mid + 1, end);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int start, int end, int idx) {
  if(start == end)
    return start;
  int mid = (start + end) / 2;
  if(tree[node * 2] >= idx)
    return query(node * 2, start, mid, idx);
  else
    return query(node * 2 + 1, mid + 1, end, idx - tree[node * 2]);
}

void update(int node, int start, int end, int val) {
  if(start == end) {
    tree[node] = 0;
    return;
  }
  int mid = (start + end) / 2;
  if(val <= mid)
    update(node * 2, start, mid, val);
  else
    update(node * 2 + 1, mid + 1, end, val);
  tree[node] = tree[node * 2] + tree[node *  2 + 1];
}

int main() {
  fastIO;
#ifdef LOCAL
  freopen("input.in", "rt", stdin);
#endif
  int t;
  cin >> t;
  while(t--) {
    memset(tree, 0,sizeof tree);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> arr[i];
    build(1, 1, N);
    for (int i = n; i > 0; --i) {
      int val = query(1, 1, N, i - arr[i - 1]);
      ans[i - 1] = val;
      update(1, 1, N, val);
    }
    for (int i = 0; i < n; ++i)
      cout << ans[i] << ' ';
    cout << '\n';
  }
  return 0;
}

