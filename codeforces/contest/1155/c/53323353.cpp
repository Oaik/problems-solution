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
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int const N = 3e5 + 9, OO = 1e9;

vector<ll> vec;
ll arr[N];

int main() {
  debug();
  ll n,m, a, first;
  cin >> n >> m;
  cin >> arr[0];
  first = arr[0];
  for (int i = 1; i < n; ++i) {
    cin >> arr[i];
//    vec.push_back(b - a);
  }
  ll mn = arr[1] - arr[0], la2 = 0;
  for (int i = 2; i < n; ++i) {
    mn = __gcd(arr[i] - arr[i-1], mn);
  }
  for (int i = 0; i < m; ++i) {
    cin >> a;
    if(a == 1) {
      la2 = i + 1;
      break;
    }
    if(a <= mn && mn % a == 0) {
      la2 = i + 1;
      break;
    }
  }
  if(la2 <= 0) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  cout << first << " " << la2;
  return 0;
}
