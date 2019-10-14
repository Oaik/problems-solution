#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9;

int arr[26], arrr[26];
int ss[26][N];

int main() {
  debug();
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    ++arrr[c - 'a'];
    ss[c - 'a'][arrr[c - 'a']] = i+1;
  }
  cin >> n;
  while (n--) {
    string str;
    cin >> str;
    clr(arr, 0);
    for (int i = 0; i < (int) str.size(); ++i)
      ++arr[str[i] - 'a'];
    int mx = 0;
    for (int i = 0; i < 26; ++i) {
      if (arr[i] == 0)
        continue;
      mx = max(mx, ss[i][arr[i]]);
    }
    cout << mx << '\n';
  }
  return 0;
}
