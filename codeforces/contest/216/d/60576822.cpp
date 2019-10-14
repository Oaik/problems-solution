#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e3 + 9, M = 3e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

vector<int> vec[N];
int kam[N];

int main() {
  fastIO;
  int n, k, a;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> k;
    for (int j = 0; j < k; ++j) {
      cin >> a;
      vec[i].push_back(a);
    }
    sort(all(vec[i]));
    kam[i] = k;
  }
  int answer = 0;
  for (int i = 0; i < n; ++i) {
    int prv = i -1, nxt = i + 1;
    if(prv == -1)
      prv = n - 1;
    if(nxt == n)
      nxt = 0;
    int l = 0, r = 0, scoreR = 0, scoreL = 0;
    for (int j = 0; j < kam[i]; ++j) {
      while(vec[prv][l] <= vec[i][j] && l < kam[prv])
        ++scoreL, ++l;
      while(vec[nxt][r] <= vec[i][j] && r < kam[nxt])
        ++scoreR, ++r;
      if(scoreL != scoreR && j)
        ++answer;
      scoreL = 0, scoreR = 0;
    }
  }
  cout << answer;
  return 0;
}
