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
const int N = 1e5 + 9, OO = 1e9;

double A[N], B[N], res[N];

int main() {
  debug();
  int n;
  double d;
  ll sum = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> d;
    A[i] = ceil(d);
    B[i] = floor(d);
    res[i] = B[i];
    sum += B[i];
  }
  for (int i = 0; i < n; ++i) {
    if(!sum)
      break;
    if(A[i] == B[i])
      continue;
    ++sum;
    res[i] = A[i];
  }
  for (int i = 0; i < n; ++i) {
    if(abs(res[i] - 0) <= EPS)
      cout << '0' << '\n';
    else
      cout << res[i] << '\n';
  }
  return 0;
}
