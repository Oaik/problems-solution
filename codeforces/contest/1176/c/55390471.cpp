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
  cout << fixed << setprecision(4);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, OO = 1e9;

vector<vector<int>> vec(50);
int arr[] = { 4, 8, 15, 16, 23, 42 };

vector<set<int>> st(50);

int main() {
  debug();
  int n, a, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    st[a].insert(i);
  }
  int cur = -1;
  while (1) {
    for (int i = 0; i < 6; ++i) {
      if (st[arr[i]].empty()) {
        cout << n - (cnt * 6);
        return 0;
      }
      while (!st[arr[i]].empty()&&*st[arr[i]].begin() < cur)
        st[arr[i]].erase(st[arr[i]].begin());
      if (st[arr[i]].empty()) {
        cout << n - (cnt * 6);
        return 0;
      }
      cur = *st[arr[i]].begin();
      st[arr[i]].erase(st[arr[i]].begin());
    }
    ++cnt;
    cur = -1;
  }
  cout << n - (cnt * 6);
  return 0;
}
