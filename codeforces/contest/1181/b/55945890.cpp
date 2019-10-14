#include <bits/stdc++.h>
using namespace std;
//#define ll long long
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
const int N = 1e5 + 9, OO = 1e9;

//typedef int64_t ll;
typedef long long ll;

#define EL printf("\n")
#define pb push_back
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)

const int base = 1e9;
typedef vector<int> BigInt;

void Set(BigInt &a) {
  while (a.size() > 1 && a.back() == 0)
    a.pop_back();
}

void Print(BigInt a) {
  Set(a);
  printf("%d", (a.size() == 0) ? 0 : a.back());
  FORD(i,a.size()-2,0)
    printf("%09d", a[i]);
  EL;
}

BigInt Integer(string s) {
  BigInt ans;
  if (s[0] == '-')
    return ans;
  if (s.size() == 0) {
    ans.pb(0);
    return ans;
  }
  while (s.size() % 9 != 0)
    s = '0' + s;
  for (int i = 0; i < s.size(); i += 9) {
    int v = 0;
    for (int j = i; j < i + 9; j++)
      v = v * 10 + (s[j] - '0');
    ans.insert(ans.begin(), v);
  }
  Set(ans);
  return ans;
}

BigInt Integer(char c[]) {
  string s = "";
  FOR(i,0,strlen(c)-1)
    s = s + c[i];
  return Integer(s);
}

BigInt Integer(ll x) {
  string s = "";
  while (x > 0)
    s = char(x % 10 + '0') + s, x /= 10;
  return Integer(s);
}

BigInt Integer(int x) {
  return Integer((ll) x);
}

void operator >>(istream &in, BigInt &a) {
  string s;
  getline(cin, s);
  a = Integer(s);
}

void operator <<(ostream &out, BigInt a) {
  Print(a);
}

bool operator <(BigInt a, BigInt b) {
  Set(a);
  Set(b);
  if (a.size() != b.size())
    return (a.size() < b.size());
  FORD(i,a.size()-1,0)
    if (a[i] != b[i])
      return (a[i] < b[i]);
  return false;
}

bool operator >(BigInt a, BigInt b) {
  return (b < a);
}

bool operator ==(BigInt a, BigInt b) {
  return (!(a < b) && !(b < a));
}

bool operator <=(BigInt a, BigInt b) {
  return (a < b || a == b);
}

bool operator >=(BigInt a, BigInt b) {
  return (b < a || b == a);
}

bool operator <(BigInt a, int b) {
  return (a < Integer(b));
}

bool operator >(BigInt a, int b) {
  return (a > Integer(b));
}

bool operator ==(BigInt a, int b) {
  return (a == Integer(b));
}

bool operator >=(BigInt a, int b) {
  return (a >= Integer(b));
}

bool operator <=(BigInt a, int b) {
  return (a <= Integer(b));
}

BigInt max(BigInt a, BigInt b) {
  if (a > b)
    return a;
  return b;
}

BigInt min(BigInt a, BigInt b) {
  if (a < b)
    return a;
  return b;
}

BigInt operator +(BigInt a, BigInt b) {
  Set(a);
  Set(b);
  BigInt ans;
  int carry = 0;
  FOR(i,0,max(a.size(), b.size())-1)
  {
    if (i < a.size())
      carry += a[i];
    if (i < b.size())
      carry += b[i];
    ans.pb(carry % base);
    carry /= base;
  }
  if (carry)
    ans.pb(carry);
  Set(ans);
  return ans;
}

BigInt operator +(BigInt a, int b) {
  return a + Integer(b);
}

BigInt operator ++(BigInt &a) {  // ++a
  a = a + 1;
  return a;
}

void operator +=(BigInt &a, BigInt b) {
  a = a + b;
}

void operator +=(BigInt &a, int b) {
  a = a + b;
}

BigInt operator *(BigInt a, BigInt b) {
  Set(a);
  Set(b);
  BigInt ans;
  ans.assign(a.size() + b.size(), 0);
  FOR(i,0,a.size()-1)
  {
    ll carry = 0ll;
    for (int j = 0; j < b.size() || carry > 0; j++) {
      ll s = ans[i + j] + carry + (ll) a[i] * (j < b.size() ? (ll) b[j] : 0ll);
      ans[i + j] = s % base;
      carry = s / base;
    }
  }
  Set(ans);
  return ans;
}

BigInt operator *(BigInt a, int b) {
  return a * Integer(b);
}

void operator *=(BigInt &a, BigInt b) {
  a = a * b;
}

void operator *=(BigInt &a, int b) {
  a = a * b;
}

int main() {
  debug();
  string str;
  int n;
  cin >> n >> str;
  int ptr = n / 2, inc = 0;
  while (str[ptr + inc] == '0' && str[ptr - inc] == '0')
    ++inc;
  string str1, str2, str3, str4;
  if (str[ptr + inc] != '0') {
    str1 = str.substr(0, ptr + inc);
    str2 = str.substr(ptr + inc, n);
  }
  if (str[ptr - inc] != '0') {
    str3 = str.substr(0, ptr - inc);
    str4 = str.substr(ptr - inc, n);
  }
  string str5, str6;
  if((n & 1)) {
    str5 = str.substr(0, ptr + inc + 1);
    str6 = str.substr(ptr + inc + 1, n);
  }
  if (!str1.empty() && !str3.empty()) {
    BigInt a = Integer(str1);
    BigInt b = Integer(str2);
    BigInt c = a + b;
    a = Integer(str3);
    b = Integer(str4);
    BigInt d = a + b;
    BigInt mx = min(d, c);
    if(n & 1) {
      a = Integer(str5);
      b = Integer(str6);
      d = a + b;
      mx = min(d, mx);
    }
    cout << mx;
  } else if (!str1.empty()) {
    BigInt a = Integer(str1);
    BigInt b = Integer(str2);
    BigInt c = a + b;
    BigInt d;
    if(n & 1) {
      a = Integer(str5);
      b = Integer(str6);
      d = a + b;
      c = min(d, c);
    }
    cout << c;
  } else {
    BigInt a = Integer(str3);
    BigInt b = Integer(str4);
    BigInt c = a + b;
    BigInt d;
    if(n & 1) {
      a = Integer(str5);
      b = Integer(str6);
      d = a + b;
      c = min(d, c);
    }
    cout << c;
  }
}