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
const int N = 2e6 + 9, OO = 1e9;

int main() {
  debug();
  int A, B, N, AA, BB, dd;
  while (cin >> A >> B >> N) {
    AA = 0, BB = 0;
    bool can = 0;
    while (1) {
      BB = B;
      cout << "fill B\n";
      while (BB) {
        cout << "pour B A\n";
        dd = min(A - AA, BB);
        AA += dd;
        BB -= dd;
        if (AA == N || BB == N) {
          if (AA == N) {
            cout << "empty B\n";
            cout << "pour A B\n";
          }
          cout << "success\n";
          can = 1;
          break;
        }
        if (!BB)
          break;
        AA = 0;
        cout << "empty A\n";
      }
      if (can)
        break;
    }
  }
}

