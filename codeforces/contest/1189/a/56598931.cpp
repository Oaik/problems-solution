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
const int N = 1e2 + 9, OO = 2e9;

int main() {
  debug();
  int n;
  string str;
  cin >> n >> str;
  int zeros = count(all(str), '0'), ones = count(all(str), '1');
  if(zeros != ones) {
    cout << 1 << '\n';
    cout << str;
    return 0;
  }
  cout << 2 << '\n';
  cout << str.substr(0, str.size() - 1) << ' ' << str[str.size() - 1];
  return 0;
}
