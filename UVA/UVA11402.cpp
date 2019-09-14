#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e6 + 9, M = 2e6 + 1, OO = 1e9 + 1, MOD = 1e9 + 7;
const unsigned ll inf = 9e18;

int arr[M], tree[4 * M], lazy[4 * M];

void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = arr[start];
    return;
  }
  int mid = (start + end) / 2;
  build(node * 2, start, mid);
  build(node * 2 + 1, mid + 1, end);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int start, int end, int l, int r) {

  if (lazy[node] != -1) {
    if (lazy[node] == 0)
      tree[node] = 0;
    else if (lazy[node] == 1)
      tree[node] = (end - start + 1);
    else
      tree[node] = (end - start + 1) - tree[node];

    if (start != end) {

      if(lazy[node] == 2) {
        if(lazy[node * 2] == -1) {
          lazy[node * 2] = lazy[node];
        } else if(lazy[node * 2] == 2) {
          lazy[node * 2] = -1;
        } else {
          lazy[node * 2] = !lazy[node * 2];
        }
        if(lazy[node * 2 + 1] == -1) {
          lazy[node * 2 + 1] = lazy[node];
        } else if(lazy[node * 2 + 1] == 2) {
          lazy[node * 2 + 1] = -1;
        } else {
          lazy[node * 2 + 1] = !lazy[node * 2 + 1];
        }
      } else {
        lazy[node * 2] = lazy[node];
        lazy[node * 2 + 1] = lazy[node];
      }

    }
    lazy[node] = -1;
  }
  if (start > r || end < l || start > end)
    return 0;
  if (start >= l && end <= r)
    return tree[node];

  int mid = (start + end) / 2;
  int p1 = query(node * 2, start, mid, l, r);
  int p2 = query(node * 2 + 1, mid + 1, end, l, r);
  return (p1 + p2);
}

void change(int node, int start, int end, int l, int r, int qq) {
  if (lazy[node] != -1) {
    if (lazy[node] == 0)
      tree[node] = 0;
    else if (lazy[node] == 1)
      tree[node] = (end - start + 1);
    else
      tree[node] = (end - start + 1) - tree[node];

    if (start != end) {

      if(lazy[node] == 2) {
        if(lazy[node * 2] == -1) {
          lazy[node * 2] = lazy[node];
        } else if(lazy[node * 2] == 2) {
          lazy[node * 2] = -1;
        } else {
          lazy[node * 2] = !lazy[node * 2];
        }
        if(lazy[node * 2 + 1] == -1) {
          lazy[node * 2 + 1] = lazy[node];
        } else if(lazy[node * 2 + 1] == 2) {
          lazy[node * 2 + 1] = -1;
        } else {
          lazy[node * 2 + 1] = !lazy[node * 2 + 1];
        }
      } else {
        lazy[node * 2] = lazy[node];
        lazy[node * 2 + 1] = lazy[node];
      }

    }
    lazy[node] = -1;
  }

  if (start > r || end < l || start > end)
    return;
  if(start >= l && end <= r) {
    if(qq == 0)
      tree[node] = 0;
    else if(qq == 1)
      tree[node] = (end - start + 1);
    else
      tree[node] = (end - start + 1) - tree[node];

    if(start != end) {
      if(qq == 2) {
        if(lazy[node * 2] == -1) {
          lazy[node * 2] = qq;
        } else if(lazy[node * 2] == 2) {
          lazy[node * 2] = -1;
        } else {
          lazy[node * 2] = !lazy[node * 2];
        }
        if(lazy[node * 2 + 1] == -1) {
          lazy[node * 2 + 1] = qq;
        } else if(lazy[node * 2 + 1] == 2) {
          lazy[node * 2 + 1] = -1;
        } else {
          lazy[node * 2 + 1] = !lazy[node * 2 + 1];
        }
      } else {
        lazy[node * 2] = qq;
        lazy[node * 2 + 1] = qq;
      }
    }
    return;
  }

  int mid = (start + end) / 2;
  change(node * 2, start, mid, l, r,  qq);
  change(node * 2 + 1, mid + 1, end, l, r, qq);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
  fastIO
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    clr(lazy, -1);
    clr(tree, 0);
    cout << "Case " << i << ':' << endl;
    int m, cur = 1;
    cin >> m;
    while (m--) {
      int num;
      string str;
      cin >> num >> str;
      while (num--) {
        for (int j = 0; j < (int) str.size(); ++j)
          arr[cur++] = str[j] - '0';
      }
    }
    --cur;
    build(1, 1, cur);
    int q;
    cin >> q;
    char c;
    int u, v, qIdx = 1;
    for (int j = 1; j <= q; ++j) {
      cin >> c >> u >> v;
      ++u, ++v;
      if (c == 'E') {
        change(1, 1, cur, u, v, 0);
      } else if (c == 'F') {
        change(1, 1, cur, u, v, 1);
      } else if (c == 'S') {
        cout << 'Q' << qIdx++ << ':' << ' ' << query(1, 1, cur,u, v) << endl;
      } else {
        change(1, 1, cur, u, v, 2);
      }
    }
  }
  return 0;
}

