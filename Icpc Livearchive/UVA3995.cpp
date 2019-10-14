#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "rt", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(2), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 1e6 + 1, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e16;

ll board[15][15], mem[15][(1 << 15)], i = 0, j = 0;

ll solve(int r, int mask) {
  if (r == i)
    return 0;
  ll& ret = mem[r][mask];
  if (~ret)
    return ret;
  ret = -inf;
  ll nmask = (~mask) & ((1 << i) - 1);
  for (int k = nmask;; k = (k - 1) & nmask) {
    bool ok = 1;
    ll sum = 0;
    for (int q = 0; q < i; ++q) {
      if(k & (1 << q)) {
        if( ((q + 1 < i) && (k & (1 << (q + 1)))) || ((q + 1 < i) && (mask & (1 << (q + 1)))
            ) || ( (q - 1 >= 0) && (mask & (1 << (q - 1))))) {
          ok = 0;
          break;
        }
        sum += board[r][q];
      }
    }
    if(ok)
      ret = max(ret, sum + solve(r + 1, k));
    if(!k)
      break;
  }

  return ret;
}

int main() {
  fastIO;
//  read("input.in");
//  write("output.in");
  string str = "aa";
  while (!cin.eof()) {
    i = 0, j = 0;
    while (1) {
      j = 0;
      getline(cin, str);
      if (str.empty())
        break;
      stringstream ss(str);
      string stre;
      while (ss >> stre) {
        int num = stoi(stre);
        board[i][j] = num;
        ++j;
      }
      ++i;
      if (cin.eof())
        break;
    }
    if(i == 0)
      continue;
    clr(mem, -1);
    ll ans = solve(0, 0);
    cout << ans << '\n';
  }
  return 0;
}

