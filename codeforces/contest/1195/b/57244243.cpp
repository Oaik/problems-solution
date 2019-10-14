#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define readIn freopen("input.in", "rt", stdin);
#define writeOut freopen("output.in", "wt", stdout);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 4e4 + 9, OO = 1e9;

int main() {
  fastIO;
  int n, start, end, mid, target;
  cin >> n >> target;
  start = 0, end = n;
  ll res;
  while(start <= end) {
    mid = start + (end - start) / 2;
    res = n - mid;
    res *= (res + 1);
    res /= 2;
    res -= mid;
    if(res > target)
      start = mid + 1;
    else if(res < target)
      end = mid - 1;
    else {
      cout << mid;
      return 0;
    }
  }
  return 0;
}
