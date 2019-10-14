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
  cout << fixed << setprecision(0);ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int const N = 3e5 + 9, OO = 1e9;

int main() {
int v1, v2, t, d;
  debug();
  cin >> v1 >> v2 >> t >> d;
  int total = v1 + v2;
  t -= 2;
  if(v1 > v2) swap(v1, v2);
  if(v2 - v1 > d) {
    while(v1 < v2 && t) {
      v1 += d;
      total += v1;
      --t;
    }
  }
  while(t) {
    if(t == 1) {
      v2 += d;
      total += v2;
      --t;
    } else {
      v1 += d, v2 += d;
      total += v1 + v2;
      t -= 2;
    }
  }
  cout << total;
}
