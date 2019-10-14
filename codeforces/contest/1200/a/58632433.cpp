#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(5), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e6 + 9, OO = 1e9;

bool arr[10];

int main() {
  fastIO;
  int n;
  string str;
  cin >> n >> str;
  for (int j = 0; j < n; ++j) {
    char c = str[j];
    if(c == 'L') {
      for (int i = 0; i <= 9; ++i) {
        if(!arr[i]) {
          arr[i] = 1;
          break;
        }
      }
    } else if(c == 'R') {
      for (int i = 9; i >= 0; --i) {
        if(!arr[i]) {
          arr[i] = 1;
          break;
        }
      }
    } else
      arr[c - '0'] = 0;
  }
  for (int i = 0; i <= 9; ++i)
    cout << arr[i];
  return 0;
}
