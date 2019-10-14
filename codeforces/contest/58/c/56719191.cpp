#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout << fixed << setprecision(0)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, OO = 1e9;

int freq[N];

int main() {
  fastIO;
//  freopen("input.in", "rt", stdin);
  int n, m, x;
  cin >> n;
  m = n >> 1;
  for (int i = 0; i < m; ++i) {
    cin >> x;
    x = max(0, x - i);
    ++freq[x];
  }
  for (int i = m; i < n; ++i) {
    cin >> x;
    x = max(0, x - (n - i - 1));
    ++freq[x];
  }
  cout << n - (*max_element(freq + 1, freq + N));
  return 0;
}
