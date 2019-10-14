#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e6 + 9, OO = 1e9 + 9;

int flo[109][109];
int path[N];

int main() {
  fastIO;
  int n;
  cin >> n;
  char c;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> c;
      if(c == '0')
        flo[i][j] = OO;
      else
        flo[i][j] = 1;
    }
  }
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        flo[i][j] = min(flo[i][j], flo[i][k] + flo[k][j] );
  for (int i = 0; i <= n; ++i)
    flo[i][i] = 0;
  // test
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      cerr << flo[i][j] << ' ';
    cerr << endl;
  }
  vector<int> vec;
  int m, prv = 0;
  cin >> m >> path[0];
  vec.push_back(path[0]);
  for (int i = 1; i < m; ++i) {
    cin >> path[i];
    if(flo[path[prv]][path[i]] != i - prv) {
      prv = i - 1;
      vec.push_back(path[i-1]);
    }
  }
  vec.push_back(path[m - 1]);
  cout << vec.size() << '\n';
  for(int it: vec)
    cout << it << ' ';
  return 0;
}
