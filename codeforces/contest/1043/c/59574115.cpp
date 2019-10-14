#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 509, M = 1e5 + 9, OO = 1e9 + 9, MOD = 1e9 + 7;

vector<char> ans;

int main() {
  fastIO;
  string str;
  cin >> str;
  int n = str.size();
  for (int i = 0; i < n - 1; ++i) {
    if(str[i] == 'b' && (i +1 < n && str[i + 1] == 'a')) {
      ans.push_back('1');
    } else if(str[i] == 'a' && (i +1 < n && str[i + 1] == 'b')) {
      ans.push_back('1');
    } else
      ans.push_back('0');
  }
  if(str[n-1] == 'a')
    ans.push_back('1');
  else
    ans.push_back('0');
  for(char c: ans)
    cout << c << ' ';
  return 0;
}
