#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  //freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(6);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
int const N = 2e5 + 9, M = 1e5 + 9, OO = 1e9;

int arr[109];

int main() {
  debug();
  int n;
  int total = 0;
  cin >> n;
  cin >> arr[0];
  for (int i = 1; i < n; ++i) {
    cin >> arr[i];
    if((arr[i] == 2 && arr[i-1] == 1) || (arr[i] == 1 && arr[i-1] == 2))
      total += 3;
    else if((arr[i] == 1 && arr[i-1] == 3) || (arr[i] == 3 && arr[i-1] == 1))
      total += 4;
    else {
      cout << "Infinite";
      return 0;
    }
  }
  cout << "Finite\n";
  for (int i = 0; i < n; ++i) {
    if(arr[i] == 3 && arr[i+1] == 1 && arr[i+2] == 2)
      --total;
  }
  cout << total;
}
