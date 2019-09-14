#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, M = 1e6 + 1, OO = 1e9 + 1, MOD = 1e9 + 7;
const unsigned ll inf = 9e18;

int arr[N], tree[4*N];

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

int query(int node, int start, int end, int l, int r) {
  if(start > r || end < l || start > end)
    return OO;
  if(start >= l && end <= r)
    return tree[node];

  int mid = (start + end) / 2;
  int p1 = query(node * 2, start, mid, l, r);
  int p2 = query(node * 2 + 1, mid + 1, end, l, r);
  return min(p1, p2);
}

int getNodeId(int node, int start, int end, int pos) {
  if(start == pos && end == pos)
    return node;
  int mid = (start + end) / 2;
  if (start <= pos && pos <= mid)
    return getNodeId(node * 2, start, mid, pos);
  else
    return getNodeId(node * 2 + 1, mid + 1, end, pos);
}

void updateTree(int node, int start, int end, int pos) {
  if(start > pos || end < pos || start > end)
    return;
  if(start == pos && end == pos)
    return;
  int mid = (start + end) / 2;
  if (start <= pos && pos <= mid)
    updateTree(node * 2, start, mid, pos);
  else
    updateTree(node * 2 + 1, mid + 1, end, pos);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}


vector<int> num;

int main() {
  fastIO

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
  build(1, 1, n);

  bool type;
  string str;
  cin.ignore();
  for (int i = 0; i < m; ++i) {
    getline(cin, str);
    type = 0;
    if(str[0] == 'q')
      type = 1;
    string cur;
    str.pop_back();
    num.clear();
    for (int j = 6; j < (int)str.size(); ++j) {
      if(str[j] == ',') {
        num.push_back(stoi(cur));
        cur.clear();
        continue;
      }
      cur.push_back(str[j]);
    }
    num.push_back(stoi(cur));
    if(type) {
      cout << query(1, 1, n, num[0], num[1]) << '\n';
    } else {
      int l = 0, r = 1, prv = -1, cur;
      while(r < (int)num.size()) {
        cur = getNodeId(1, 1, n, num[r]);
        if(prv == -1)
          prv = getNodeId(1, 1, n, num[l]);
        swap(tree[cur], tree[prv]);
        updateTree(1, 1, n, num[l]);
        prv = cur;
        ++l, ++r;
      }
      updateTree(1, 1, n, num[l]);
    }
  }
  return 0;
}

