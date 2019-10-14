#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e6 + 9, M = 3e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

pair<int, int> tree[4*N];
string str;

void build(int node, int start, int end) {
  if(start == end) {
    if(str[start] == '(')
      tree[node] = {1, 0};
    else
      tree[node] = {0, 1};
    return;
  }
  int mid = (start + end) / 2;
  build(node * 2, start, mid);
  build(node * 2 + 1, mid + 1, end);
  pair<int, int> p1 = tree[node * 2], p2 = tree[node * 2 + 1];
  pair<int, int> p3 = {p2.first, p1.second};
  int diff = (p2.second - p1.first);
  if(diff >= 0)
    p3.second += diff;
  else
    p3.first -= diff;
  tree[node] = p3;
}

pair<int, int> query(int node, int start, int end, int l, int r) {
  if(start > r || end < l || start > end)
    return {0, 0};
  if(start >= l && end <= r)
    return tree[node];
  int mid = (start + end) / 2;
  pair<int, int> p1 = query(node * 2, start, mid, l, r), p2 = query(node * 2 + 1, mid + 1, end, l, r);
  pair<int, int> p3 = {p2.first, p1.second};
  int diff = (p2.second - p1.first);
  if(diff >= 0)
    p3.second += diff;
  else
    p3.first -= diff;
  return p3;
}

int main() {
  fastIO;
  cin >> str;
  str = '0' + str;
  int n = str.size(), m;
  build(1, 1, n);
  cin >> m;
  int u, v;
  while(m--) {
    cin >> u >> v;
    pair<int, int> p3 = query(1, 1, n, u, v);
    int len = (v - u + 1) - (p3.first + p3.second);
    if(len & 1)
      return -1;
    cout << len << '\n';
  }
  return 0;
}
