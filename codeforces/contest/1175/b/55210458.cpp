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
const int N = 1e5 + 9;
const ll OO = (1LL << 32) - 1;

vector<int> ans;

int main() {
  debug();
  int n;
  ll total = 0, cnt, bb = 1;
  int overflow = 0;
  string str;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> str;
    if (str == "add") {
      if (ans.empty()) {
        total += 1;
        if (total > OO) {
          cout << "OVERFLOW!!!";
          return 0;
        }
      } else {
        if(bb > OO || overflow) {
          cout << "OVERFLOW!!!";
          return 0;
        }
        total += bb;
        if (total > OO) {
          cout << "OVERFLOW!!!";
          return 0;
        }
      }
    } else if (str == "end") {
      if(!ans.empty() && !overflow) {
        bb /= ans.back();
        ans.pop_back();
      } else if(overflow)
        --overflow;
    } else {
      cin >> cnt;
      if(bb > OO)
        ++overflow;
      else {
        bb *= cnt;
        ans.push_back(cnt);
      }
    }
  }
  cout << total;
  return 0;
}
