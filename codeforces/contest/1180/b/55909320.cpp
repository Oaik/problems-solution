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
const int N = 1e5 + 9, OO = 1e9;

vector<int> arr;

int main() {
  debug();
  int n, a;
  bool sign = 1;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if (a >= 0)
      a = (a * -1) - 1;
    if (a < 0)
      sign = 1 - sign;
    arr.push_back(a);
  }
  if (n == 1) {
    cout << max(a, (a * -1) - 1);
    return 0;
  }
  if (!sign) {
    auto mm = min_element(arr.begin(), arr.end());
    int val = *mm;
    arr[distance(begin(arr), mm)] = (val * -1) - 1;
  }
  for (int i = 0; i < n; ++i)
    cout << arr[i] << ' ';
  return 0;
}
