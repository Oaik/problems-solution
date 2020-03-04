#include<bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define ll long long
#define fastIO cout << fixed << setprecision(10), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 1e6 + 9, M = 2e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

int arr[10], n, m, mem[N][2];

int solve(int n, bool player) {
  if(n < 0)
    return player;
  if(!n)
    return !player;
  int& ret = mem[n][player];
  if(~ret)
    return ret;
  ret = !player;
  for (int i = 0; i < m; ++i)
    if(solve(n - arr[i], !player) == player)
      return ret = player;
  return ret;
}

int main() {
  fastIO;
//  #ifndef ONLINE_JUDGE
//    freopen("input.in", "rt", stdin);
//  #endif
  while(cin >> n) {
    cin >> m;
    for (int i = 0; i < m; ++i)
      cin >> arr[i];
    memset(mem, -1, sizeof mem);
    if(solve(n, 0))
      cout << "Ollie wins\n";
    else
      cout << "Stan wins\n";
  }

  return 0;
}

