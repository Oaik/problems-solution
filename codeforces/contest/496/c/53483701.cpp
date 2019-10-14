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
  cout << fixed << setprecision(4);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
int const N = 1e6 + 9, M = 1e5 + 9, OO = 1e9;

string arr[109];
bool dl[109];

int main() {
  debug();
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  int numOfOp = 0;
  bool col = 0;
  string str1, str2;
  for (int i = 1; i < n; ++i) {
    str1 = "", str2 = "";
    for (int j = 0; j < m; ++j) {
      if(!dl[j]) {
        str2 += arr[i][j];
        str1 += arr[i-1][j];
      } else {
        str2 += '.';
        str1 += '.';
      }
    }
    col = 0;
    while(str2 < str1) {
      for (int j = 0; j < m; ++j) {
        if(str2[j] == '.')
          continue;
        if(str2[j] < str1[j]) {
          dl[j] = 1;
          ++numOfOp;
          str2[j] = '.';
          str1[j] = '.';
          i = 0;
          break;
        }
      }
      break;
    }
  }
//  for (int i = 0; i < n; ++i) {
//    str1 = "";
//    for (int j = 0; j < m; ++j) {
//      if(!dl[j]) {
//        str1 += arr[i][j];
//      } else {
//        str1 += '.';
//      }
//    }
//    cout << str1 << endl;
//  }
  cout << numOfOp;
}
