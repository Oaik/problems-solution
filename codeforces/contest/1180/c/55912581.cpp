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
  cout << fixed << setprecision(12);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9;

deque<int> q;

pair<int, int> ans[N];
int arr[N];

int main() {
  debug();
  int n, m, a, mx = 0;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    mx = max(a, mx);
    q.push_back(a);
  }
  int inc = 0, A, B;
  while (q.front() != mx) {
    ++inc;
    A = q.front();
    q.pop_front();
    B = q.front();
    q.pop_front();
    q.push_back(min(A, B)), q.push_front(max(A, B));
    ans[inc] = {A, B};
  }
  q.pop_front();
  int le = inc;
  for (int i = 1; i < n; ++i) {
    ++inc;
    arr[i] = q.front();
    ans[inc] = {mx, arr[i]};
    q.pop_front();
  }
  int sz = inc - le;
  ll b;
  for (int i = 0; i < m; ++i) {
    cin >> b;
    if (b <= inc) {
      cout << ans[b].first << ' ' << ans[b].second;
    } else {
      b -= (le);
      --b;
      b %= (sz);
      b += le + 1;
      cout << ans[b].first << ' ' << ans[b].second;
    }
    cout << endl;
//    cout << '\n';
  }
  return 0;
}
