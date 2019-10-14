#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(10), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
double const EPS = 1e-8, PI = acos(-1);
const int N = 3e5 + 9, OO = 1e9;

int arr[N];
vector<int> vec;

int main() {
  fastIO;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  for (int i = 1; i < n; ++i)
    vec.push_back(arr[i] - arr[i-1]);
  sort(all(vec));
  int ans = 0;
  m = n - m;
  for (int i = 0; i < m; ++i)
    ans += vec[i];
  cout << ans;
  return 0;
}
