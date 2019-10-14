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
const int N = 1e4 + 9, OO = 1e9;
ll mem[N][4];

int n, a, b, c;

ll dp(int tot, int num) {
    if(tot == n) return 0;
    if(tot > n) return -1e6;
    ll& ret = mem[tot][num];
    if(ret != -1) return ret;
    ll c1 = dp(tot + a, 0)+1;
    ll c2 = dp(tot + b, 1)+1;
    ll c3 = dp(tot + c, 2)+1;
    return ret = max(c1, max(c2, c3));
}

int main() {
  debug();
  clr(mem, -1);
  cin >> n>> a>>b >>c;
  cout << dp(0,0);
}
