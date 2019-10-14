#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e6 + 9, OO = 1e9;

ll arr[101];

int main() {
  debug();
  int q;
  cin >> q;
  while(q--) {
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
      cin >> arr[i];
    sort(arr , arr + n);
    ll req = arr[0] + k;
    bool can = 1;
    for (int i = 0; i < n; ++i) {
      if(abs(req - arr[i]) > k) {
        can = 0;
        cout << -1 << '\n';
        break;
      }
    }
    if(can)
      cout << req << '\n';
  }
}
