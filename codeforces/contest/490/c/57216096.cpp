#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define readIn freopen("input.in", "rt", stdin);
#define writeOut freopen("output.in", "wt", stdout);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e6 + 9, M = 4e4 + 9, OO = 1e9;

ll pre[N], suf[N];

int main() {
  fastIO;
  string str;
  ll a, b;
  cin >> str >> a >> b;
  int n = str.size();
  ll md = 0, p = 1;
  for (int i = 0; i < n; ++i) {
    md *= 10;
    md += str[i] - '0';
    md %= a;
    pre[i] = md;
  }
  md = 0;
  for (int i = n-1; i >= 0; --i) {
    md += (str[i] - '0' ) * p;
    md %= b;
    p *= 10;
    p %= b;
    suf[i] = md;
  }
  --n;
  for (int i = 0; i < n; ++i) {
    if(pre[i] == 0 && suf[i+1] == 0 && str[i+1] != '0') {
      cout << "YES\n";
      cout << str.substr(0, i+1) << '\n';
      cout << str.substr(i+1) << '\n';
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
