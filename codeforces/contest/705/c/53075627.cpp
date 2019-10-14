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

int arr[N], cnt[N];
queue<pair<int, int>> q;

int main() {
  debug();
  int n, m, a, b, x = 0, req, total = 0, idx = 0;
  pair<int, int> tp;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    if (a == 1) {
      ++idx, ++total, ++arr[b];
      q.push( { b, idx });
    } else if (a == 2) {
      total -= arr[b];
      cnt[b] = idx, arr[b] = 0;
    } else {
      if (b > x) {
        req = b - x;
        x = b;
        for (int i = 0; i < req && !q.empty(); ++i) {
          tp = q.front();
          q.pop();
          if (tp.second > cnt[tp.first]) {
            --arr[tp.first];
            --total;
          }
        }
      }
    }
    cout << total << '\n';
  }
}
