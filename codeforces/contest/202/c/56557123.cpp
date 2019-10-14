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
const int N = 1e2 + 9;
const ll OO = 2e18;
int arr[102];

int main() {
  debug();
  int cur = 3, cnt = 0, req = 8;
  arr[1] = 1;
  for (int i = 2; i < 6; ++i)
    arr[i] = 3;
  cur = 5;
  arr[3] = cur;
  for (int i = 6; i <= 101; ++i) {
      arr[i] = cur;
      ++cnt;
      if(cnt == req) {
        cur += 2;
        cnt = 0;
        req += 4;
      }
  }
  int x;
  cin >> x;
  cout << arr[x];
  return 0;
}
