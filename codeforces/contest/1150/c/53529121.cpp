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

int arr[9];

int main() {
  debug();
  int n, a;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    ++arr[a];
  }
  if (arr[1] == 0) {
    for (int i = 0; i < arr[2]; ++i) {
      cout << 2 << " ";
    }
    return 0;
  }
  if (arr[2] == 0) {
    for (int i = 0; i < arr[1]; ++i) {
      cout << 1 << " ";
    }
    return 0;
  }
  cout << 2 << " " << 1 << " ";
  --arr[2];
  --arr[1];
  for (int i = 0; i < arr[2]; ++i) {
    cout << 2 << " ";
  }
  for (int i = 0; i < arr[1]; ++i) {
    cout << 1 << " ";
  }
}