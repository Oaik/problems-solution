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
const int N = 1e5 + 9, OO = 1e9 + 9;

int arr[N], n, evens = 0, odds = 0;
multiset<pair<int, int>> st1, st2;
bool vis[N];

int main() {
  debug();
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    if(arr[i] & 1)
      ++odds;
    else
      ++evens;
  }
  if(evens && odds)
    sort(arr, arr+ n);

  for (int i = 0; i < n; ++i) {
    cout << arr[i] << ' ';
  }
  return 0;
}