#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "r", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 2e5 + 9, M = 2e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

vector<int> prefixT(string pat) {
  int m = pat.size();
  vector<int> pre(m);
  for (int i = 1, k = 0; i < m; ++i) {
    while(k > 0 && pat[k] != pat[i])
      k = pre[k - 1];
    if(pat[k] == pat[i])
      pre[i] = ++k;
    else
      pre[i] = k;
  }
  return pre;
}

int main() {
  fastIO;
//  read("input.in");
//  write("input.in");
  int t;
  cin >>t;
  for (int j = 1; j <= t; ++j) {
    cout << "Test case #" << j << '\n';
    int n;
    string str;
    cin >> n >> str;
    vector<int> prefix = prefixT(str);
    for (int i = 1; i < n; ++i) {
      int val = i + 1 - prefix[i], ans = (i + 1) / val;
      if((i + 1) % (val) == 0 && ans != 1)
        cout << i + 1 << ' ' << ans << '\n';
    }
    cout << '\n';
  }
  return 0;
}

