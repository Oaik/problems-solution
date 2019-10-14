#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, M = 50, OO = 1e9 + 9, MOD = 1e9 + 7;

int arr[N];
pair<int, ll> vv[N]; // cnt, cost

int main() {
  fastIO
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  sort(arr, arr + n);
  ll best = OO;
  for (int i = 0; i < n; ++i) {
    int val = arr[i];
    ++vv[val].first;
    if(vv[val].first == k) {
      best = min(best, vv[val].second);
    }
    int cost = 0;
    while(val) {
      val /= 2;
      ++cost;
      ++vv[val].first, vv[val].second += cost;
      if(vv[val].first == k) {
        best = min(best, vv[val].second);
      }
    }
  }
  cout << best;
  return 0;
}
