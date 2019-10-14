#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  //freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(6);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
int const N = 2e5 + 9, M = 1e5 + 9, OO = 1e9;

int arr[29];

int main() {
  debug();
  int n, m;
  string str, strA, strB;
  cin >> n;
  while(n--) {
    cin >> str;
    m = str.size();
    strA = "", strB = "";
    memset(arr, 0, sizeof(arr));
    for(char c: str) {
      ++arr[c - 'a'];
    }
    for (int i = 0; i < 26; i += 2) {
      while(arr[i]) {
        strA += char((i + 'a'));
        --arr[i];
      }
    }
    for (int i = 1; i < 26; i += 2) {
      while(arr[i]) {
        strB += char((i + 'a'));
        --arr[i];
      }
    }
    str = strA + strB;
    bool f = 0;
    for (int i = 1; i < m; ++i) {
      if(abs(str[i] - str[i - 1]) == 1) {
        f = 1;
        break;
      }
    }
    if(!f) {
      cout << str << '\n';
      continue;
    }
    str = strB + strA;
    f = 0;
    for (int i = 1; i < m; ++i) {
      if(abs(str[i] - str[i - 1]) == 1) {
        f = 1;
        break;
      }
    }
    if(!f) {
      cout << str << '\n';
      continue;
    }
    cout << "No answer\n";
  }
}
