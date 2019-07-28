#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 1e2 + 9, OO = 1e9;
int n;

// BigInteger
#define int64 long long
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define pb push_back
struct BigInteger {
  static const int BASE = 1000000000; // 10^9

  vector<int64> digits;

  BigInteger() {
    digits.clear();
    digits.pb(0);
  }
  BigInteger(int64 number) {
    digits.clear();
    do {
      digits.pb(number % BASE);
      number /= BASE;
    } while (number);
  }

  BigInteger operator + (const BigInteger &b) const {
    BigInteger res = BigInteger();
    res.digits.resize(max(b.digits.size(), digits.size()));
    int64 remainder = 0;
    rep(i, res.digits.size()) {
      if (i < (int)digits.size()) remainder += digits[i];
      if (i < (int)b.digits.size()) remainder += b.digits[i];
      res.digits[i] = remainder % BASE;
      remainder /= BASE;
    }
    while (remainder) {
      res.digits.pb(remainder % BASE);
      remainder /= BASE;
    }
    return res;
  }

  BigInteger operator * (const BigInteger &b) const {
    BigInteger res = BigInteger();
    res.digits = vector<int64>(b.digits.size() + digits.size() - 1, 0);
    rep(i, digits.size()) rep(j, b.digits.size())
      res.digits[i + j] += digits[i] * (int64)b.digits[j];
    int64 remainder = 0;
    rep(i, res.digits.size()) {
      remainder += res.digits[i];
      res.digits[i] = remainder % BASE;
      remainder /= BASE;
    }
    while (remainder) {
      res.digits.pb(remainder % BASE);
      remainder /= BASE;
    }
    return res;
  }

  void print() {
    printf("%lld", digits.back());
    repr(i, (int)digits.size() - 1) printf("%09lld", digits[i]);
  }

  static BigInteger power(const BigInteger &b, int64 k) {
    if (k == 0) return BigInteger(1);
    if (k == 1) return b;
    BigInteger res = power(b, k / 2);
    res = res * res;
    if (k & 1) return res * b;
    return res;
  }
};
// End BigInterger

map<pair<int, int>, BigInteger> mem;
BigInteger DP(int sum = 0, int num = 1) {
  if (sum > n)
    return 0;
  if (sum == n)
    return 1;
  if (mem.find({sum, num}) != mem.end()) {
    return mem[{sum, num}];
  }
  BigInteger ret = mem[{sum, num}];
  ret = 0;
  ret = ret + DP(sum + 1, 1);
  ret = ret + DP(sum + 1, 4);
  ret = ret + DP(sum + 2, 2);
  ret = ret + DP(sum + 3, 3);
  mem[{sum, num}] = ret;
  return ret;
}

int main() {
//  fastIO;
  n = 1000;
  DP();
  while (cin >> n) {
    BigInteger b1 = mem[{1000-n, 1}];
    b1.print();
    puts("");
  }
  return 0;
}

