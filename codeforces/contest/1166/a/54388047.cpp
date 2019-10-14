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
const int N = 1e2 + 9, OO = 2e9 + 9;

int arr[27];

int main() {
  debug();
  int n;
  cin >> n;
  string str;
  for (int i = 0; i < n; ++i) {
    cin >> str;
    ++arr[str[0] - 'a'];
  }
  int total = 0, num1, num2;
  for (int i = 0; i < 27; ++i) {
    num1 = arr[i] / 2;
    num2 = arr[i] / 2 + (arr[i] & 1);
    for (int i = 1; i < num1; ++i)
      total += i;
    for (int i = 1; i < num2; ++i)
      total += i;
  }
  cout << total;
}
