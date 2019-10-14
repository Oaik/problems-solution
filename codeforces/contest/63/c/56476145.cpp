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
const int N = 1e5 + 9, OO = 1e9;

vector<string> gen;

void precal() {
  for (int i = 0; i <= 9; ++i) {
    for (int j = 0; j <= 9; ++j) {
      if(i == j)
        continue;
      for (int k = 0; k <= 9; ++k) {
        if(k == i || k == j)
          continue;
        for (int e = 0; e <= 9; ++e) {
          if(e == i || e == k || e == j)
            continue;
          string str = to_string(i) + to_string(j) + to_string(k) + to_string(e);
          gen.push_back(str);
        }
      }
    }
  }
}

int main() {
  debug();
  precal();
  int n;
  cin >> n;
  struct ans {
    string num;
    int x, y;
  } ans[n];
  for (int i = 0; i < n; ++i) {
    int x, y;
    string str;
    cin >> str >> x >> y;
    ans[i] = {str, x, y};
  }
  int cnt = 0;
  string cur;
  for(string test: gen) {
    bool can = 1;
    for (int i = 0; i < n; ++i) {
      int tempX = ans[i].x, tempY = ans[i].y;
      for (int j = 0; j < 4; ++j) {
        if(find(all(ans[i].num), test[j] ) != ans[i].num.end()) {
          if(test[j] != ans[i].num[j])
            --tempY;
          else
            --tempX;
        }
      }
      if(tempY != 0 || tempX != 0) {
        can = 0;
        break;
      }
    }
    if(can) {
      ++cnt;
      cur = test;
    }
  }
  if(!cnt)
    cout << "Incorrect data";
  else if(cnt == 1)
    cout << cur;
  else
    cout << "Need more data";
  return 0;
}
