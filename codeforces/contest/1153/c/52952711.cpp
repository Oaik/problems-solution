#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define all(v)    ((v).begin()),((v).end())
#define clr(a,b)  memset(a,b,sizeof(a))
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);
// freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int const N = 1e5 + 9, OO = 1e9;

void exit() {
  cout << ":(";
  exit(0);
}

int main() {
  debug();
  int n;
  string str;
  cin >> n >> str;
  if( (n & 1) || str[0] == ')' || str[n-1] == '(')
    exit();
  int t = n / 2, m = n/2;
  for (int i = 0; i < n; ++i) {
    if(str[i] == '(')
      --t;
  }
  for (int i = 0; i < n; ++i) {
    if(str[i] == ')')
      --m;
  }
  if(t < 0 || m < 0)
    exit();
  for (int i = 0; i < n; ++i) {
    if(str[i] == '?') {
      if(t) {
        str[i] = '(';
        --t;
      } else
        str[i] = ')';
    }
  }
  int total = 0;
  for (int i = 0; i < n-1; ++i) {
    if(str[i] == '(')
      ++total;
    else
      --total;
    if(total <= 0)
      exit();
  }
  --total;
  if(total != 0)
    exit();
  cout << str;
  return 0;
}
