#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8, pi = acos(-1);
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  //	freopen("output.in", "wt", stdout);
#endif
}

int const N = 1e5 + 9, OO = 1e9;

int evens[N], odds[N];

int main() {
  cout << fixed << setprecision(12);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  debug();
  int n, a, evI = 0, odI = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if(a % 2 == 0) {
      evens[evI] = a;
      ++evI;
    }
    else {
      odds[odI] = a;
      ++odI;
    }
  }
  int nums = abs(evI - odI) - 1;
  if(evI == odI)  {
    cout << 0;
    return 0;
  }
  sort(evens, evens + evI);
  sort(odds, odds+ odI);
  int sumEv = 0, sumOd = 0;
  if(evI > odI) {
    for (int i = 0; i < nums; ++i) {
      sumEv += evens[i];
    }
    cout << sumEv;
  } else {
    for (int i = 0; i < nums; ++i) {
      sumOd += odds[i];
    }
    cout << sumOd;
  }

  return 0;
}