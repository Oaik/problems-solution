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

int const N = 3e5 + 9, OO = 1e9;

vector<int> vec;

int main() {
  debug();
  int n;
  string str;
  cin >> n;
  int req = (n-11)/2;
  char c;
  int c8 = 0, reqc = 0;
  for (int i = 0; i < n; ++i) {
    cin >> c;
    str.push_back(c);
    if(c == '8') {
      ++c8;
      if(c8 <= req)
        ++reqc;
      vec.push_back(i);
    }
  }
  if(c8 <= req) {
    cout << "NO";
    return 0;
  }

  if(vec[req] - reqc <= req)
    cout << "YES";
  else
    cout << "NO";
}