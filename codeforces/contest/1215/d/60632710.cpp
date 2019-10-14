#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 3e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

int main() {
  fastIO;
  int n;
  string str;
  cin >> n >> str;
  vector<int> v1, v2;
  int total1 = 0, total2 = 0;
  for (int i = 0; i < n/2; ++i) {
    if(str[i] == '?')
      v1.push_back(i);
    else
      total1 += str[i] - '0';
  }
  for (int i = n / 2; i < n; ++i) {
    if(str[i] == '?')
      v2.push_back(i);
    else
      total2 += str[i] - '0';
  }
  while(!v1.empty() || !v2.empty()) {
    int sz = v1.size() + v2.size();
    if(sz == 2) {
      if(v1.empty()) {
        if(total1 - total2 == 9) {
          cout << "Bicarp\n";
        } else {
          cout << "Monocarp\n";
        }
        return 0;
      } else if(v2.empty()) {
        if(total2 - total1 == 9) {
          cout << "Bicarp\n";
        } else {
          cout << "Monocarp\n";
        }
        return 0;
      } else {
        if(total1 - total2 != 0) {
          cout << "Monocarp\n";
        } else {
          cout << "Bicarp\n";
        }
        return 0;
      }
      break;
    }
    if(!v1.empty()) {
      v1.pop_back();
      total1 += 9;
      if(!v2.empty()) {
        total2 += 9;
        v2.pop_back();
      } else
        v1.pop_back();
      continue;
    }
    if(!v2.empty()) {
      v2.pop_back();
      total2 += 9;
      if(!v1.empty()) {
        total1 += 9;
        v1.pop_back();
      } else {
        v2.pop_back();
      }
    }
  }
  if(total1 != total2) {
    cout << "Monocarp\n";
  } else {
    cout << "Bicarp\n";
  }
  return 0;
}
