#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 1e2 + 9, OO = 1e9;
ll type[N], val[N], q[N], c;
int main() {
  fastIO;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> type[i];
    if(type[i] == 1) {
      cin >> val[i];
      q[i + 1] = 1;
    } else {
      cin >> val[i] >> c;
      q[i + 1] = val[i] * c;
    }
  }
  ++n;
  for (int i = 1; i <= n; ++i)
    q[i] += q[i-1];
  --n;
  int m, t;
  cin >> m;
  while(m--) {
    cin >> c;
    while(1) {
      t = lower_bound(q, q+n, c) - q;
      --t;
      if(type[t] == 1) {
        cout << val[t] << ' ';
        break;
      }
      c -= q[t];
      c = (c - 1) % (val[t]) + 1;
    }
  }
  return 0;
}
