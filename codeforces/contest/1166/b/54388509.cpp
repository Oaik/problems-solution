#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, OO = 2e9 + 9;

bool primes[N];

void sieve() {
  int n = 1e5;
  primes[0] = primes[1] = 1;
  for (ll i = 2; i * i < n; ++i) {
    if(!primes[i]) {
      for (int j = i * i; j < n; j += i) {
        primes[j] = 1;
      }
    }
  }
}

int main() {
  debug();
  int n;
  string vol = "aeiou";
  cin >> n;
  if(primes[n]) {
    cout << -1;
    return 0;
  }
  for (ll i = 2; i * i <= n; ++i) {
    if(n % i == 0) {
      if(n / i >= 5 && i >= 5) {
        int r = i, c = n/i;
        for (int i = 0; i < r; ++i) {
          for (int j = 0; j < c; ++j)
            cout << vol[(i + j) % 5];
        }
        return 0;
      }
    }
  }
  cout << -1;
}
