#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin); //  freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-6, PI = acos(-1);
int const N = 1e5 + 9, M = 1e5 + 9, OO = 1e7;

int main() {
  debug();
  int a, m, c, d;
  cin >> a >> m >> c >> d;
  --c, --d;
  int rowA = c/m, rowB = d/m;
  int posA = c - (rowA * m), posB = d - (rowB * m);
  ++d, ++c;
  if((posA == 0 && (posB == m-1 || d == a)) || (rowA == rowB)) {
    cout << 1;
  } else if((abs(posA - posB) == 1 && posA >= posB) || (abs(rowA - rowB) == 1) || (d == a) || (posA == 0) || (posB == m-1)) {
    cout << 2;
  } else {
    cout << 3;
  }
}
