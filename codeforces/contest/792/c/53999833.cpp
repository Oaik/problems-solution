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
const int N = 1e5 + 9, OO = 1e9;

bool la2[N];
string str;
int f = 0, s = 0, n;

bool awlmra() {
  for (int i = 1; i < n; ++i) {
    if (str[i] == '1' || str[i] == '4' || str[i] == '7') {
      la2[i] = 1;
      return 1;
    }
  }
  if ((str[0] == '1' || str[0] == '4' || str[0] == '7') && str[1] != '0') {
    la2[0] = 1;
    return 1;
  } else {
    int cnt = 2;
    for (int i = n - 1; i >= 0 && cnt; --i) {
      if (str[i] == '2' || str[i] == '5' || str[i] == '8') {
        la2[i] = 1;
        --cnt;
      }
    }
    if (!cnt)
      return 1;
    if((str[0] == '1' || str[0] == '4' || str[0] == '7')) {
      la2[0] = 1;
      return 1;
    }
  }
  return 0;
}

bool tanymra() {
  for (int i = 1; i < n; ++i) {
    if (str[i] == '2' || str[i] == '5' || str[i] == '8') {
      la2[i] = 1;
      return 1;
    }
  }
  if ((str[0] == '2' || str[0] == '5' || str[0] == '8') && str[1] != '0') {
    la2[0] = 1;
    return 1;
  } else {
    int cnt = 2;
    for (int i = n - 1; i >= 0 && cnt; --i) {
      if (str[i] == '1' || str[i] == '4' || str[i] == '7') {
        la2[i] = 1;
        --cnt;
      }
    }
    if (!cnt)
      return 1;
    if((str[0] == '2' || str[0] == '5' || str[0] == '8')) {
      la2[0] = 1;
      return 1;
    }
  }
  return 0;
}

int main() {
  debug();
  cin >> str;
  n = str.size();
  if(n == 1) {
    if(stoi(str) % 3 == 0)
      cout << str;
    else
      cout << -1;
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (str[i] == '3' || str[i] == '6' || str[i] == '9' || str[i] == '0')
      continue;
    if (str[i] == '1' || str[i] == '4' || str[i] == '7')
      ++s;
    else
      ++f;
  }
  int remF = f % 3, remS = s % 3;
  bool can = 0;
  if (remF == remS) {
    cout << str;
    return 0;
  } else {
    if (remF == 0) {
      if (remS == 1) {
        can = awlmra();
      } else {
        can = tanymra();
      }
    } else if (remF == 1) {
      if (remS == 0) {
        can = tanymra();
      } else {
        can = awlmra();
      }
    } else {  // remF == 2
      if (remS == 0) {
        can = awlmra();
      } else {
        can = tanymra();
      }
    }
  }
  if (!can) {
    cout << -1;
    return 0;
  }
  int start = 0;
  bool zero = 0;
  for (int i = 0; i < n; ++i) {
    if (la2[i])
      continue;
    if (!start && str[i] == '0') {
      zero = 1;
      continue;
    }
    ++start;
    zero = 0;
    cout << str[i];
  }
  if (zero)
    cout << 0;
  else if (start == 0)
    cout << -1;
}
