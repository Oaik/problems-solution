#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
double const EPS = 1e-15, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e5;

int main() {
  fastIO;
  int n, m;
  string str;
  cin >> n >> m >> str;
  int x = n - 1;
  ++str[x];
  while(x >= 0 && x < n) {
    if(str[x] == 'a' + m) {
      str[x] = 'a';
      --x;
      ++str[x];
    } else if(x > 0 && str[x] == str[x-1])
      ++str[x];
    else if(x > 1 && str[x] == str[x - 2])
      ++str[x];
    else
      ++x;
  }
  if(x < 0)
    cout << "NO";
  else
    cout << str;
  return 0;
}
