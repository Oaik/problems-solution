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

vector<ll> atLeast;

int main() {
  debug();
  ll n;
  int cnt = 0;
  cin >> n;
  atLeast.push_back(1);
  atLeast.push_back(2);
  while(atLeast[atLeast.size() - 1] + atLeast[atLeast.size() - 2] < 1e18) {
    atLeast.push_back(atLeast[atLeast.size() - 1] + atLeast[atLeast.size() - 2]);
  }
  for (int i = 1; i < atLeast.size(); ++i) {
    if(atLeast[i] > n)
      break;
    ++cnt;
  }
  cout << cnt;
}
