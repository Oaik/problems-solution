#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("galactic.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e3 + 9, M = 3e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

ll mem[N][N];
int n, k;

ll DP(int games, int players) {
  if(games == 0) { // BASE CASE: no games left
    if(players == 0) // all players at least play one game
      return 1;
    return 0;
  }
  if(players < 0) // INVALID CASE: no players left
    return 0;
  ll& ret = mem[games][players];
  if(~ret)
    return ret;
  ret = 0;
  ll c2 = (DP(games - 1, players - 1) * players) % MOD; // A player did'nt play before (will play this game) + can't play another game
  ll c1 = (DP(games - 1, players) * (k - players)) % MOD; // A player played before Can He (play this game) ?
  return ret = (c1 + c2) % MOD;
}

int main() {
  fastIO;
  read;
//  clock_t startTime = clock();

  int t;
  cin >> t;
  while(t--) {
    cin >> n >> k;
    if(n < k) {
      cout << 0 << '\n';
      continue;
    }
    clr(mem, -1);
    ll res = DP(n, k);
    cout << res << '\n';
  }

//  clock_t endTime = clock();
//  cerr << endl << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;

  return 0;
}
