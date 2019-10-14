#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(2), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9;

int main() {
  fastIO;
  int n;
  cin >> n;
  if(!(n & 1)) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  if(n == 1) {
    cout << 1 << ' ' << 2;
    return 0;
  }
  vector<int> vec;
  n *= 2;
  vector<int> ans(n);
  for (int i = n; i >= 1; --i)
    vec.push_back(i);
  int t = 0;
  n /= 2;
  for (int i = 0; i < n; ++i) {
    if(t) {
      ans[i + n] = vec.back();
      vec.pop_back();
      ans[i] = vec.back();
      vec.pop_back();
    } else {
      ans[i] = vec.back();
      vec.pop_back();
      ans[i + n] = vec.back();
      vec.pop_back();
    }
    t ^= 1;
  }
  n *= 2;
  for (int i = 0; i < n; ++i)
    cout << ans[i] << ' ';
  return 0;
}
