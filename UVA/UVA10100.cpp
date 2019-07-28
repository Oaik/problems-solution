#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 3e5 + 9, OO = 1e9;

bool isValid(char c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

vector<string> vec1, vec2;
int mem[1001][1001];

int DP(int x, int y) {
  if(x == (int)vec1.size())
    return 0;
  if(y == (int)vec2.size())
    return 0;

  int& ret = mem[x][y];
  if(~ret)
    return ret;
  ret = 0;
  int c1 = 0, c2 = 0;
  if(vec1[x] == vec2[y])
    return ret = DP(x+1, y+1) + 1;
  c1 = DP(x+1, y);
  c2 = DP(x, y + 1);
  return ret = max(c1, c2);
}

int main() {
  fastIO;
//  read;
  string str, temp;
  int idx = 1;
  while(getline(cin, str)) {
    stringstream oo;
    vec1.clear();
    vec2.clear();
    clr(mem, -1);
    oo << str;
    while(oo >> str){
      temp.clear();
      for(char c: str) {
        if(isValid(c))
          temp += c;
        else {
          if(!temp.empty())
            vec1.push_back(temp);
          temp.clear();
        }
      }
      if(!temp.empty())
        vec1.push_back(temp);
    }
    getline(cin, str);
    oo.clear();
    oo << str;
    while(oo >> str){
      temp.clear();
      for(char c: str) {
        if(isValid(c))
          temp += c;
        else {
          if(!temp.empty())
            vec2.push_back(temp);
          temp.clear();
        }
      }
      if(!temp.empty())
        vec2.push_back(temp);
    }
    if(vec1.empty() || vec2.empty()) {
      cout << setw(2) << idx++ << '.' << ' ' << "Blank!\n";
      continue;
    }
    int cnt = DP(0, 0);
    cout << setw(2) << idx++ << ". Length of longest match: " << cnt << '\n';
  }
}

