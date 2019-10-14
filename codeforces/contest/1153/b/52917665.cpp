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

int const N = 1e2 + 9, OO = 1e9;

int arr[N], dist[N];

int main() {
  debug();
  int n, m, h;
  cin >> n >> m >> h;
  for (int i = 0; i < m; ++i) {
    cin >> arr[i];
  }
  int a;
  for (int i = 0; i < n; ++i) {
    cin >> dist[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m ; ++j) {
      cin >> a;
      if(a == 0)
        cout << "0 ";
      else
        cout << min(arr[j],dist[i])  << " ";
    }
    cout << '\n';
  }
  return 0;
}