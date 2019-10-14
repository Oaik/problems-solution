#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(5), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9;

vector<pair<int, pair<int, int>>> vec;

int main() {
  fastIO;
  int t;
  cin >> t;
  while(t--) {
    int n, a, b;
    cin >> n;
    n = 2 * n - 1;
    vec.clear();
    ll A = 0, B = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a >> b;
      vec.push_back({a, {b, i + 1}});
      A += a, B += b;
    }
    sort(all(vec));
    ll E = 0, O = 0;
    for (int i = 0; i < n; ++i) {
      if(i & 1)
        O += vec[i].second.first;
      else
        E += vec[i].second.first;
    }
    O += vec[n-1].second.first;
    cout << "YES\n";
    if(E > (B / 2)) {
      for (int i = 0; i < n; i += 2)
        cout << vec[i].second.second << ' ';
    } else {
      cout << vec[n-1].second.second << ' ';
      for (int i = 1; i < n; i += 2)
        cout << vec[i].second.second << ' ';
    }
    cout << '\n';
  }
  return 0;
}
