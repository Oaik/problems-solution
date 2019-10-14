#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
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
const int N = 5e5 + 9, OO = 1e9;

char changeChar(char c) {
  if(c == '1') return '0';
  return '1';
}

int main() {
  debug();
  int n;
  string str;
  cin >> n >> str;
  char c = '1';
  for (int i = 0; i < n; ++i) {
    if(i + 1 < n && str[i] == '(' && str[i+1] == ')') {
      cout << c << c;
      ++i;
      continue;
    }
    if(str[i] == '(') {
        cout << c;
        c = changeChar(c);
    } else {
      c = changeChar(c);
      cout << c;
    }
  }
}
