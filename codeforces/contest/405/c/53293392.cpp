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
//  cout << fixed << setprecision(0);
//  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int const N = 1e3 + 9, OO = 1e9;

int main() {
//  debug();
  int n, q, type, a;
  char b;
  bool prd = 0;
  scanf("%d",&n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf(" %c", &b);
      if( j == i && b == '1')
        prd = !prd;
    }
  }
  scanf("%d",&q);
  for (int i = 0; i < q; ++i) {
    scanf("%d",&type);
    if (type != 3)
      scanf("%d",&a);
    if (type == 1 || type == 2)
      prd = !prd;
    else
      printf((prd) ? "1" : "0");
  }
}
