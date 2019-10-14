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
const int N = 2e6 + 9, OO = 1e9;

int arr[N];
double exp(double a, double b){
    double t(1);
    for(int i = 0;i<b;++i)
        t *= a;
    return t;
}
double n_root_(double num, double n_){
    double x;
    double A(num);
    double dx;
    double eps(10e-6);
    double n(n_);
    x = A * 0.5;
    dx = (A/exp(x,n-1)-x)/n;
    while(dx >= eps || dx <= -eps){
        x = x + dx;
        dx = (A/exp(x,n-1)-x)/n;
    }
   return x;
}

int main() {
  debug();
  int n, a;
  cin >> n;
  ll total = 0;
  for (int i = 0; i < n; ++i)
    cin >> arr[i], total += arr[i];
  sort(arr, arr + n, greater<int>());
//  if (n == 1) {
//    cout << total;
//    return 0;
//  }
  ll start = 0, end = 40, mid, ans, val = 1;
  while(start <= end) {
    mid = start + (end - start) / 2;
    val = 1;
    for (int i = 0; i < mid; ++i) {
      val *= 4;
    }
    if(val == n) {
      ans = mid;
      break;
    } else if(val < n)
      start = mid + 1;
    else
      end = mid - 1;
  }
  ll inc = 1;
  while (ans) {
    for (int i = 0; i < inc; ++i)
      total += arr[i];
    inc *= 4;
    --ans;
  }
  cout << total;
}
