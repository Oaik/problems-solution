#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e6 + 9, OO = 1e9;
 
int main() {
  fastIO;
  // freopen("input.in", "rt", stdin);//  freopen("output.in", "wt", stdout);
  int n, a, b, c,d ,e, f;
  cin >> n;
  vector<vector<int>> v(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 6; ++j) {
      cin >> a;
      v[i].push_back(a);
    }
    sort(all(v[i]));
  }
  sort(all(v));
  // for (int i = 0; i < n; ++i)
  // {
  //   for (int j = 0; j < 6; ++j)
  //   {
  //     cout << v[i][j] << ' ';
  //   }
  //   cout << endl;
  // }

  bool can = 0;
  for (int i = 1; i < n && !can; ++i) {
    if(v[i] == v[i-1])
      can = 1;
  }
  if(can)
    cout << "Twin snowflakes found.";
  else
    cout << "No two snowflakes are alike.";
  return 0;
}
