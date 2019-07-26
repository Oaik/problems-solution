#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
double const EPS = 1e-15, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9;

ll arr[39][39];

int main() {
  fastIO;
  int n, a, b, idx = 0, mx = 0;
  while(cin >> n) {
    if(!n) {
      cout << "matrix for city " << idx++ << '\n';
      continue;
    }
    clr(arr, 0);
    mx = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a >> b;
      ++arr[a][b];
      mx = max(mx, max(a, b));
    }
    for (int k = 0; k <= mx; ++k) {
      for (int i = 0; i <= mx; ++i) {
        for (int j = 0; j <= mx; ++j) {
          arr[i][j] += (arr[i][k] * arr[k][j]);
        }
      }
    }
    for (int k = 0; k <= mx; ++k) {
      if(arr[k][k]) {
        for (int i = 0; i <= mx; ++i) {
          for (int j = 0; j <= mx; ++j) {
            if(arr[i][k] && arr[k][j])
              arr[i][j] = -1;
          }
        }
      }
    }
    cout << "matrix for city " << idx++ << '\n';
    for (int i = 0; i <= mx; ++i) {
      for (int j = 0; j <= mx; ++j) {
        if(j)
          cout << ' ';
        cout << arr[i][j];
      }
      cout << '\n';
    }
  }
  return 0;
}

