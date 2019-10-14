#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 5e4 + 9, M = 4e4 + 9, OO = 1e9;
 
 
int main() {
  fastIO;
  // freopen("input.in", "rt", stdin);//  freopen("output.in", "wt", stdout);
  int n, m, t;
  cin >> t;
  while(t--) {
    cin >> n >> m;
    char arr[n][m];
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        cin >> arr[i][j];
    vector<int> vecA, vecB;
    int ans1 = OO, res = 0;
    for (int i = 0; i < n; ++i) {
      res = 0;
      for (int j = 0; j < m; ++j)
        res += (arr[i][j] == '.');
      vecA.push_back(res);
    }
    res = 0;
    for (int j = 0; j < m; ++j) {
      res = 0;
      for (int i = 0; i < n; ++i)
        res += (arr[i][j] == '.');
      vecB.push_back(res);
    }
    int total = OO;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        total = min(total, vecA[i] + vecB[j] - (arr[i][j] == '.'));
    cout << total << '\n';
  }
  return 0;
}
