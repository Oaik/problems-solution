#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  // freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(4);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
int const N = 1e6 + 9, M = 1e5 + 9, OO = 1e9;

string arr[109];
bool dl[109];

int main() {
  debug();
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  int numOfOp = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if(!dl[j] && arr[i][j] < arr[i-1][j]) {
        ++numOfOp, dl[j] = 1;
        arr[i][j] = '.', arr[i-1][j] = '.';
        i = 0;
        break;
      } else if(!dl[j] && arr[i][j] > arr[i-1][j])
        break;
    }
  }
  cout << numOfOp;
}
