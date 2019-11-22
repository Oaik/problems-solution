#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "r", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(6), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 2e5 + 9, M = 3e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

int main() {
  fastIO;
//  read("input.in");
//  write("input.in");
  int x;
  while (cin >> x, x) {
    vector<int> vec;
    for (ll i = 1; i * i <= x; ++i) {
      if (x % i == 0) {
        vec.push_back(i);
        if(x / i != i)
          vec.push_back(x/i);
      }
    }
    int cnt = 0;
    for (int i = 0; i < (int)vec.size(); ++i) {
      for (int j = 0; j < (int)vec.size(); ++j) {
        if( (ll)vec[i] * (ll)vec[j] / (ll)__gcd(vec[i], vec[j]) == x)
          ++cnt;
      }
    }
    cout << x << ' ' << (cnt + 1) / 2 << '\n';
  }
  return 0;
}

