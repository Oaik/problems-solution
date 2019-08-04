#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, OO = 1e9;

int arr[2*N], tree[10*N];

void build(ll node, ll start, ll end) {
  if(start == end) {
    if(arr[start] == 0)
      tree[node] = 0;
    else if(arr[start] > 0)
      tree[node] = 1;
    else
      tree[node] = -1;
  } else {
    int mid = (start + end) / 2;
    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);
    int zeros = (tree[2*node] == 0) + (tree[2*node + 1] == 0),
        neg = (tree[2*node] < 0) + (tree[2*node + 1] < 0);
    if(zeros)
      tree[node] = 0;
    else if(neg == 1)
      tree[node] = -1;
    else
      tree[node] = 1;
  }
}

void update(ll node, ll start, ll end, ll idx, ll val) {
  if (start == end) {
    arr[idx] = val;
    if(arr[idx] == 0)
      tree[node] = 0;
    else if(arr[idx] > 0)
      tree[node] = 1;
    else
      tree[node] = -1;
  } else {
    ll mid = (start + end) / 2;
    if (start <= idx and idx <= mid) {
      update(2 * node, start, mid, idx, val);
    } else {
      update(2 * node + 1, mid + 1, end, idx, val);
    }
    int zeros = (tree[2*node] == 0) + (tree[2*node + 1] == 0),
        neg = (tree[2*node] < 0) + (tree[2*node + 1] < 0);
    if(zeros)
      tree[node] = 0;
    else if(neg == 1)
      tree[node] = -1;
    else
      tree[node] = 1;
  }
}

ll query(ll node, ll start, ll end, ll l, ll r) {
  if(r < start || end < l) {
    return 1ll;
  }
  if(l <= start && end <= r) {
    return tree[node];
  }
  ll mid = (start + end) / 2;
  ll p1 = query(node * 2, start, mid, l, r);
  ll p2 = query(node * 2 + 1, mid + 1, end, l, r);
  return (p1 * p2);
}

int main() {
  fastIO;
  ll n, k;
  while(cin >> n >> k) {
    for (int i = 1; i <= n; ++i)
      cin >> arr[i];
    build(1,1, n);

    char c;
    ll u, v;
    while(k--) {
      cin >> c >> u >> v;
      if(c == 'C')
        update(1, 1, n, u, v);
      else {
        ll num = (query(1, 1, n, u, v));
        if(num == 0)
          cout << '0';
        else if(num > 0)
          cout << '+';
        else
          cout << '-';
      }
    }
    cout << '\n';
  }

  return 0;
}

