#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  // freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int const N = 1e5 + 9, OO = 1e9;
vector<int> cat;
vector<string> catt;
vector<int> vec;

int main() {
  debug();
  const int yy = 20, qq = 19;
  int n;
  for (int i = 1; i < 30; ++i) {
    n = pow(2, i) - 1;
    cat.push_back(n);
    catt.push_back(to_string(n));
  }
  cin >> n;
  if (binary_search(all(cat), n)) {
    cout << 0;
    return 0;
  }
  bitset<(int)yy> m(n);
  string str = m.to_string();
  int ress;
  string res;
  bool f = 1, la = 0;
  if (!(n & 1)) {
    ress = 0;
    bitset<(int)yy> mm(ress);
    res = mm.to_string();
    vec.push_back(0);
    for (int i = 0; i < yy; ++i) {
      if (res[i] == str[i])
        str[i] = '0';
      else
        str[i] = '1';
    }
    la = 0;
    for (int i = qq; i >= 0; --i) {
      if (str[i] == '0') {
        str[i] = '1';
        la = 1;
        break;
      }
      str[i] = '0';
    }
    if (!la) {
      str = '1' + str;
    }
    if (binary_search(all(catt), str) && f) {
      f = 0;
    }
  }
  while (f) {
    f = 0;
    for (int j = 0; j < yy; ++j) {
      if (str[j] == '0') {
        f = 1;
        ress = cat[yy - j - 1];
        bitset<yy> mm(ress);
        res = mm.to_string();
        vec.push_back(yy - j);
        for (int i = 0; i < yy; ++i) {
          if (res[i] == str[i])
            str[i] = '0';
          else
            str[i] = '1';
        }
        la = 0;
        for (int i = qq; i >= 0; --i) {
          if (str[i] == '0') {
            str[i] = '1';
            la = 1;
            break;
          }
          str[i] = '0';
        }
        if (!la) {
          str = '1' + str;
        }
        if (binary_search(all(catt), str)) {
          f = 1;
          break;
        }
        break;
      }
    }
  }
//  cout << str;
  int nn = (vec.size() * 2);
  cout << nn << '\n';
  for (auto it : vec) {
    cout << it << " ";
  }
}
