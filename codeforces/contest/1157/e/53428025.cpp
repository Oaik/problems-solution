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

int const N = 2e5 + 9, OO = 1e9;

int A[N];
multiset<int> B;
vector<int> C;

int main() {
  debug();
  int n, a;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  for (int i = 0; i < n; ++i) {
    cin >> a;
    B.insert(a);
  }
  int val, x, y;
  for (int i = 0; i < n; ++i) {
    if (A[i] == 0) {
      auto yy = (B.upper_bound(0));
      auto xx = (B.begin());
      x = *xx;
      if (yy == B.end()) {
        C.push_back((x + A[i]) % n);
        B.erase(xx);
        continue;
      }
      y = *yy;
      if ((x + A[i]) % n <= (y + A[i]) % n) {
        C.push_back((x + A[i]) % n);
        B.erase(xx);
      } else {
        C.push_back((y + A[i]) % n);
        B.erase(yy);
      }
    } else {
      val = n - A[i];
      auto xx = (B.lower_bound(val));
      auto yy = (B.upper_bound(val));
      if (xx == B.end() && yy != B.end()) {
        if(yy == B.end()) {
          auto aa = (B.begin());
          x = *aa;
          C.push_back((x + A[i]) % n);
          B.erase(aa);
          continue;
        }
        y = *yy;
        C.push_back((y + A[i]) % n);
        B.erase(yy);
      } else if (yy == B.end()) {
        if(xx == B.end()) {
          auto aa = (B.begin());
          x = *aa;
          C.push_back((x + A[i]) % n);
          B.erase(aa);
          continue;
        }
        x = *xx;
        C.push_back((x + A[i]) % n);
        B.erase(xx);
      } else {
        x = *xx, y = *yy;
        if ((x + A[i]) % n <= (y + A[i]) % n) {
          C.push_back((x + A[i]) % n);
          B.erase(xx);
        } else {
          C.push_back((y + A[i]) % n);
          B.erase(yy);
        }
      }
    }
  }
  for(int i: C) {
    cout << i << " ";
  }
}
