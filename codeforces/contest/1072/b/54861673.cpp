#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
const int N = 1e5 + 9, OO = 1e9 + 9;

int a[N], b[N], mem[N][5][5], n;

bool dp(int i, int prv, int cur) {
  if(i == n) {
    mem[i][prv][cur] = 1;
    return 1;
  }
  int &ret = mem[i][prv][cur];
  if(ret != -1)
    return ret;
  ret = 0;
  for (int j = 0; j < 4; ++j) {
    if( ((cur | j) == a[i]) && ((cur & j) == b[i]))
      ret = dp(i+1, cur, j);
  }
  return ret;
}

void print(int i, int prv) {
  if(i == n+1)
    return;
  for (int j = 0; j < 4; ++j) {
    if(mem[i][prv][j] == 1) {
      cout << j << " ";
      print(i+1, j);
      break;
    }
  }
}

int main() {
  debug();
  cin >> n;
  --n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < n; ++i)
    cin >> b[i];
  clr(mem, -1);
  if(dp(0, 4, 0)) {
    cout << "YES\n";
//    cout << 0 << " ";
    print(0, 4);
  } else if(dp(0, 4, 1)) {
    cout << "YES\n";
//    cout << 1 << " ";
    print(0, 4);
  } else if(dp(0, 4, 2)) {
    cout << "YES\n";
//    cout << 2 << " ";
    print(0, 4);
  } else if(dp(0, 4, 3)) {
    cout << "YES\n";
    print(0, 4);
  } else {
    cout << "NO";
  }
//  cout << dp(0, 4, 0) << endl;
//  cout << dp(0, 4, 1) << endl;
//  cout << dp(0, 4, 2) << endl;
//  cout << dp(0, 4, 3) << endl;
  return 0;
}
