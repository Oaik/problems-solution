#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "r", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 2e5 + 9, M = 1e2 + 9, OO = 1e8 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

double fact[15];

double rec(string str) {
  if(str.empty())
    return 0;
  double cnt = 0;
  for (int i = 1; i < (int)str.size(); ++i)
    if(str[i] < str[0])
      ++cnt;
  cnt *= fact[(int)str.size() - 1];
  for (int i = 0; i < 26 && cnt; ++i) {
    int oc = 0;
    for (int j = 0; j < (int)str.size(); ++j) {
      if(str[j] == 'a' + i)
        ++oc;
    }
    cnt /= fact[oc];
  }
  return cnt + rec(str.substr(1));
}

int main() {
  fastIO;
//  read("input.in");
//  write("input.in");
  fact[1] = 1, fact[0] = 1;
  for (int i = 2; i < 31; ++i)
    fact[i] = fact[i-1] * i;
  string str;
  while(cin >> str, str != "#")
    cout << setw(10) << rec(str) + 1 << '\n';
  return 0;
}
