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
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-9, PI = acos(-1);
int const N = 1e5 + 9, M = 1e5 + 9, OO = 1e9;

bool vis[N];
int first[N], last[N];

int main() {
  debug();
  int n, k, a;
  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    cin >> a;
    if(!vis[a])
      first[a] = i + 1;
    last[a] = i + 1;
    vis[a] = 1;
  }
  int total = 0;
  for (int i = 1; i <= n; ++i) {
    if(!vis[i]) {
      if(i == 1 || i == n)
        total += 2;
      else
        total += 3;
      continue;
    }
    if(i != 1 && first[i] > first[i-1] && first[i] > last[i-1]) {
      ++total;
    }
    if(i != n && first[i] > first[i+1] && first[i] > last[i+1]) {
      ++total;
    }
  }
  cout << total;
}
