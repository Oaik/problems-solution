#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e3 + 9, M = 1e2 + 9, OO = 1e9;

int arr[N][M];
vector<pair<int, int>> vec;

int main() {
  fastIO;
  int n,
  m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      cin >> arr[i][j];
    for (auto it : vec) {
      if (arr[i][it.first] > arr[i][it.second])
        swap(arr[i][it.first], arr[i][it.second]);
    }
    for (int j = 0; j < m; ++j) {
      for (int w = j + 1; w < m; ++w) {
        if (k) {
          if (arr[i][j] < arr[i][w]) {
            swap(arr[i][j], arr[i][w]);
            vec.push_back( { w, j });
          }
        } else {
          if (arr[i][j] > arr[i][w]) {
            swap(arr[i][j], arr[i][w]);
            vec.push_back( { j, w });
          }
        }
      }
    }
  }
  cout << vec.size() << '\n';
  for (auto it : vec)
    cout << it.first + 1 << ' ' << it.second + 1 << '\n';
  return 0;
}
