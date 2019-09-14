#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e6 + 9, M = 3e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const unsigned ll inf = 9e18;

int arr[M];
pair<int, int> tree[4*M];

void build(int node, int start, int end) {
  if(start == end) {
    if(arr[start] == 1) {
      tree[node].first = 1;
      tree[node].second = 0;
    } else {
      tree[node].first = 0;
      tree[node].second = 1;
    }
    return;
  }

  int mid = (start + end) / 2;
  build(node * 2, start, mid);
  build(node * 2 + 1, mid + 1, end);
  pair<int, int> p1 = tree[node * 2];
  pair<int, int> p2 = tree[node * 2 + 1];
  tree[node] = {p2.first, p1.second};
  int diff = p1.first - p2.second;
  if(diff >= 0)
    tree[node].first += diff;
  else
    tree[node].second -= diff;
}

bool query() {
  return (tree[1].first == 0 && tree[1].second == 0);
}

void update(int node, int start, int end, int idx) {
  if(start == end) {
    tree[node].first = !tree[node].first;
    tree[node].second = !tree[node].second;
    return;
  }
  int mid = (start + end) / 2;
  if(idx > mid)
    update(node * 2 + 1, mid + 1, end, idx);
  else
    update(node * 2, start, mid, idx);

  pair<int, int> p1 = tree[node * 2];
  pair<int, int> p2 = tree[node * 2 + 1];
  tree[node] = {p2.first, p1.second};
  int diff = p1.first - p2.second;
  if(diff >= 0)
    tree[node].first += diff;
  else
    tree[node].second -= diff;
}

int main() {
//  fastIO
  for (int t = 0; t < 10; ++t) {
    printf("Test %d:\n", t + 1);
    int n, q;
    scanf("%d ", &n);
    char c;
    for (int i = 1; i <= n; ++i) {
      scanf("%c", &c);
      if(c == '(')
        arr[i] = 1;
      else
        arr[i] = -1;
    }
    build(1, 1, n);
    scanf("%d", &q);
    int m;
    for (int i = 0; i < q; ++i) {
      scanf("%d", &m);
      if(!m) {
        if(query())
          printf("YES\n");
        else
          printf("NO\n");
      } else
        update(1, 1, n, m);
    }
  }
  return 0;
}

