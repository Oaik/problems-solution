#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "r", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(7), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 2e3 + 9, M = 2e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

int L[N], R[N], n;

int main() {
  fastIO;
//  read("input.in");
//  write("input.in");
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      cin >> L[i];
    sort(L, L + n);
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        cin >> R[j];
      sort(R, R + n);
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
      for (int i = 0; i < n; ++i)
        q.push({L[i] + R[0], 0});
      for (int i = 0; i < n; ++i) {
        auto it = q.top();
        L[i] = it.first;
        q.pop();
        q.push({it.first - R[it.second] + R[it.second + 1],it.second + 1});
      }
    }
    cout << L[0];
    for (int i = 1; i < n; ++i)
      cout << ' ' << L[i];
    cout << '\n';
  }
  return 0;
}

