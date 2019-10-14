#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "rt", stdin)
#define fastIO cout << fixed << setprecision(6), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e2 + 9, M = 1e6 + 1, OO = 1e9 + 1;
const ll inf = 2e18, MOD = 1e9 + 7;

string str;
int mem[(1 << 13)], n;

int solve(int mask, int prv) {
  if(!mask)
    return 0;
  int& ret = mem[mask];
  if(~ret)
    return ret;
  ret = 0;
  for (int i = 1; i < n; ++i) {
    if((mask & (1 << (i-1))) && (mask & (1 << (i)))) {
      if(i - 2 > 0 && !(mask & (1 << (i-2)))) {
        int nmask = mask;
        nmask &= ~((1 << (i)));
        nmask &= ~((1 << (i - 1)));
        nmask |= (1 << (i - 2));
        ret = max(ret, solve(nmask, i) + 1);
      }
    }
    if( (mask & (1 << (i-1))) && (mask & (1 << (i)))) {
      if(i + 1 < n && !(mask & (1 << (i+1)))) {
        int nmask = mask;
        nmask &= ~((1 << (i)));
        nmask &= ~((1 << (i - 1)));
        nmask |= (1 << (i + 1));
        ret = max(ret, solve(nmask, i) + 1);
      }
    }
  }
  return ret;
}

int main() {
  fastIO;
  int t;
  cin >> t;
  while(t--) {
    cin >> str;
    n = str.size();
    clr(mem, -1);
    int myMask = 0;
    for (int i = 0; i < n; ++i) {
      if(str[i] == 'o')
        myMask |= (1 << i);
    }
    int curPub = __builtin_popcount(myMask);
    cout << curPub - solve(myMask, 12);
    cout << '\n';
  }
  return 0;
}

