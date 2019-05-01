#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  // freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(5);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int const N = 1e5 + 9, OO = 1e9;
int main() {
  debug();
  double a, b, c;
  double totalCars, totalCows, shown, totshow;
  double total;
  while (cin >> totalCows >> totalCars >> shown) {
    total = totalCars + totalCows;
    totshow = total - shown - 1;
    a = totalCars * ((totalCars - 1) / totshow);
    b = totalCows * (totalCars / (totshow ));
    c = a + b;
    c /= total;
    cout << c << endl;
  }
}

