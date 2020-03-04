#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "r", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 1e4 + 9, M = 2e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

int main() {
  fastIO;
//  read("input.in");
//  write("input.in");
  int T,
  A, B, C, M, N;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> A >> B >> C >> M >> N;

    int seq[10005];
    seq[0] = A;
    for (int i = 1; i < N; i++) {
      seq[i] = (seq[i - 1] * B + C) % M + 1;
    }

    for (int i = 1; i < N; i++) {
      seq[i] += seq[i - 1];
    }

    int rest[10005] = { 0 };
    rest[0] = 1;

    int ans = 0;
    for (int i = 0; i < N; i++) {
      int r = seq[i] % M;
      ans += rest[r];
      rest[r]++;
    }
    cout << "Case " << t << ": " << ans << endl;
  }
  return 0;
}

