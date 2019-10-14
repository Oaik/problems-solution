#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1179858 + 9, OO = 1e9;

bool notPrime[N];
vector<int> primes;

void sieve() {
  notPrime[1] = notPrime[0] = 1;
  for (ll i = 2; i < N; ++i) {
    if(!notPrime[i]) {
      for (ll j = i * i; j < N; j += i)
        notPrime[j] = 1;
    }
  }
  for (int i = 0; i < N; ++i) {
    if(!notPrime[i])
      primes.push_back(i);
  }
}

vector<int> pa;

void genAllPa() {
  string str, rev;
  for (int i = 1; i <= N; ++i) {
    rev = str = to_string(i);
    reverse(all(rev));
    if(rev == str)
      pa.push_back(i);
  }
}

int dcmp(double a, double b) {
  if(fabs(a - b) <= EPS)
    return 0;
  else if(a > b)
    return 1;
  else
    return -1;
}

int main() {
  fastIO;
  sieve();
  genAllPa();
  int ans = 0, a, b, i1, i2;
  cin >> a >> b;
  double AA;
  for (int i = 1; i < N; ++i) {
    i1 = upper_bound(all(primes), i) - primes.begin();
    i2 = upper_bound(all(pa), i) - pa.begin();
    AA = i2 * a;
    AA /= b;
    if(dcmp(AA, i1) >= 0)
      ans = i;
  }
  cout << ans;
  return 0;
}
