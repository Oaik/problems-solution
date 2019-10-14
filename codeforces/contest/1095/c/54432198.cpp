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
const int N = 2e5 + 0, OO = 1e9 + 9;

priority_queue<int> q;

int main() {
  debug();
  int n, m;
  cin >> n >> m;
  for (int i = pow(2, 30); i > 0; i /= 2) {
    if (n >= i)
      q.push(i), n -= i;
  }
  if ((int)q.size() > m) {
    cout << "NO";
    return 0;
  } else if ((int)q.size() < m) {
    while ((int)q.size() != m) {
      if (q.top() == 1) {
        cout << "NO";
        return 0;
      }
      q.push(q.top() / 2);
      q.push(q.top() / 2);
      q.pop();
    }
  }
  cout << "YES\n";
  while (!q.empty()) {
    cout << q.top() << " ";
    q.pop();
  }
  return 0;
}
