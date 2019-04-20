#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define all(v)    ((v).begin()),((v).end())
#define clr(a,b)  memset(a,b,sizeof(a))
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);
// freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int const N = 2e9 + 9, OO = 1e9;

vector<ll> vec;
void preproc() {
  int lps = 1e5 + 2;
  for (int i = 3; i < lps; i += 2)
    vec.push_back((ll) i * (ll) i);
}

void printIt(ll x, ll y) {
  cout << "Line = " << x << ", column = " << y << '.' << '\n';
}

int main() {
  debug();
  preproc();
  ll n, k, z,zz, s1, s2, s3, s4, s5;
  while (cin >> n >> k, (n != 0) || (k != 0)) {
    if(k == 1) {
      printIt((n/2) +1, (n/2) +1);
      continue;
    }
    if (binary_search(all(vec), k)) {
      z = sqrt(k);
      s1 = k;
      printIt(z + (n-z)/2, z + (n-z)/2);
      continue;
    } else {
       zz = *(upper_bound(all(vec), k));
//      z = (it - vec.begin());
      z = sqrt(zz);
      s1 = z * z;
    }
    s3 = s1 - (2 * (z - 1));
    s2 = s3 - (z - 1), s4 = s1 - (z - 1), s5 = s2 - (z - 2);
    if (k >= s5 && k <= s2) {
      printIt(n - (n-z)/2, s2 - k + 1 + ((n-z)/2));
    } else if (k >= s2 && k <= s3) {
      printIt(s3 - k + 1 + ((n-z)/2), 1 + ((n-z)/2));
    } else if (k >= s3 && k <= s4) {
      printIt(1 + ((n-z)/2),k - s3 + 1 + ((n-z)/2));
    } else if (k >= s4 && k <= s1) {
      printIt(k - s4 + 1 + ((n-z)/2), n - ((n-z)/2));
    }
  }
  return 0;
}

