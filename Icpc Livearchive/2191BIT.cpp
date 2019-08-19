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

ll arr[N], tree[4*N], mxVal;

void update(int idx, int val) {
  int lastVal = arr[idx];
  arr[idx] = val;
  val -= lastVal;
  while(idx <= mxVal) {
    tree[idx] += val;
    idx += (idx & -idx);
  }
}

ll get(int idx) {
  ll sum = 0;
  while(idx > 0) {
    sum += tree[idx];
    idx -= (idx & -idx);
  }
  return sum;
}

int main() {
  fastIO;
//  read;
//  write;
  int n, c = 0, a;
  while(cin >> n, n) {
    if(c)
      cout << '\n';
    cout << "Case " << ++c << ':' << '\n';
    clr(arr, 0);
    clr(tree, 0);
    mxVal = n;
    for (int i = 1; i <= n; ++i) {
      cin >> a;
      update(i, a);
    }
    string str;
    int u, v;
    while(cin >> str, str != "END") {
      cin >> u >> v;
      if(str == "M") {
        ll sum = get(v) - get(u - 1);
        cout << sum << '\n';
      } else {
        update(u, v);
      }
    }
  }
  return 0;
}

