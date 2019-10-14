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

int n;
ll total = 0;
string str;

void funfun() {
  ++n, ++total;
  str = to_string(n);
  while(str.size() && str[str.size() - 1] == '0') {
    str.pop_back();
  }
  n = stoi(str);
}

int main() {
  debug();
  cin >> n;

  while (n - 10 >= 0) {
    funfun();
  }
  cout << total + 9;
  return 0;
}