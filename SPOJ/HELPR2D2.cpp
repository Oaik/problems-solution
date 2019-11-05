#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "r", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 1e6 + 9, M = 1e5 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

int tree[N], n;

void build(int node, int start, int end) {
  if(start == end) {
    tree[node] = n;
    return;
  }
  int mid = (start + end) / 2;
  build(node * 2, start , mid);
  build(node * 2 + 1, mid + 1, end);
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int start, int end, int val) {
  if(tree[node] < val)
    return -1;
  if(start == end)
    return start;
  int mid = (start + end ) / 2;
  int p1 = query(node * 2, start, mid, val);
  if(p1 != -1)
    return p1;
  return query(node * 2 + 1, mid + 1, end, val);
}

void update(int node, int start, int end, int idx, int val) {
  if(start == end) {
    tree[node] -= val;
    return;
  }
  int mid = (start + end) / 2;
  if(idx <= mid)
    update(node * 2, start, mid, idx, val);
  else
    update(node * 2 + 1, mid + 1, end, idx, val);
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int getVal(int node, int start, int end, int idx) {
  if(start == end)
    return tree[node];
  int mid = (start + end) / 2;
  if(idx <= mid)
    return getVal(node * 2, start, mid, idx);
  else
    return getVal(node * 2 + 1, mid + 1, end, idx);
}

int main() {
//  fastIO;
//  read("input.in");
//  write("input.in");
  int t;
  char str[16];
  scanf("%d", &t);
  while(t--) {
    set<int> st;
    int m;
    scanf("%d %d", &n, &m);
    build(1, 1, M);
    while(m--) {
      scanf("%s", str);
      int a = -1, b = -1;
      if(str[0] != 'b') {
        b = 1;
        a = atoi(str);
      } else {
        scanf("%d %d", &b, &a);
      }
      if(b)
        m -= b - 1;
      while(b--) {
        int idx = query(1, 1, M, a);
        st.insert(idx);
        update(1, 1, M, idx, a);
      }
    }
    int numShips = st.size();
    int totalWaste = 0;
    for(int it: st)
      totalWaste += getVal(1, 1, M, it);
    printf("%d %d\n", numShips, totalWaste);
  }
  return 0;
}

