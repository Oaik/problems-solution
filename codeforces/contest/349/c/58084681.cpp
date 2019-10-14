#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);odeforces.comodeforces.com
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 1e2 + 9, OO = 1e9;

int arr[N];

int main() {
  fastIO;
  int n;
  ll mx = 0, sum = 0;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i], sum += arr[i], mx = max((ll)arr[i], mx);

  cout << max(sum / (n-1) + (sum % (n-1) != 0), mx);
  return 0;
}
