#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  // freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int const N = 3e5 + 9, OO = 1e9;

int arr[19];

int main() {
  debug();
  string str;
  int n, a;
  cin >> n;
  cin >> str;
  for (int i = 1; i < 10; ++i) {
    cin >> a;
    arr[i] = a;
  }
  int cc = -1;
  for (int i = 0; i < n; ++i) {
    char c = str[i];
    if(arr[c - '0'] > c - '0') {
      cc = i;
      break;
    }
  }
  if(cc == -1) {
    cout << str;
    return 0;
  }
  for (int i = cc; i < n; ++i) {
    char c = str[i];
    if((arr[c - '0'] < c - '0'))
      break;
    str[i] = ((char)arr[c - '0'] + '0');
  }
  cout << str;
}