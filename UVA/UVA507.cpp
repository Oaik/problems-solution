#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "rt", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, M = 1e6 + 1, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 2e18;

ll arr[109][109], pre[109][109];

int main() {
  fastIO;
//  read("input.in");
//  write("output.in");
  int t;
  cin >> t;
  for(int i = 1; i <= t; ++i) {
    int n, a, ans = -OO, cur = 0, st = 1,beg = 1, nd = -1, dist = 0;
    cin >> n;
    for (int i = 1; i < n; ++i) {
      cin >> a;
      cur += a;
      if(cur > ans || (cur == ans && i + 1 - st > dist)) {
        beg = st;
        nd = i + 1;
        dist = nd - beg;
        ans = cur;
      }
      if(cur < 0)
        cur = 0, st = i + 1;
    }
    if(ans > 0) {
      cout << "The nicest part of route " << i << " is between stops " << beg << " and " << nd;
    } else {
      cout << "Route " << i << " has no nice parts";
    }
    if(t)
      cout << '\n';
  }
  return 0;
}

