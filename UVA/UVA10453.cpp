#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e3 + 9, M = 4e4 + 9, OO = 1e9;

string str;
int mem[N][N];

int DP(int i, int j) {
  if (i >= j)
    return 0;
  int& ret = mem[i][j];
  if (~ret)
    return ret;
  ret = OO;
  if (str[i] == str[j])
    return ret = DP(i + 1, j - 1);
  int c1 = DP(i + 1, j) + 1, c2 = DP(i, j - 1) + 1;
  return ret = min(c1, c2);
}
deque<char> le, ri;
int idx = 0;
void printPath(int i, int j) {
  if (i == j) {
    le.push_back(str[i]);
    return;
  }
  if (i > j)
    return;
  if (str[i] == str[j]) {
    ri.push_front(str[i]);
    le.push_back(str[i]);
    return printPath(i + 1, j - 1);
  }
  int c1 = DP(i + 1, j) + 1, c2 = DP(i, j - 1) + 1, ans = DP(i, j);
  if (c1 == ans) {
    ri.push_front(str[i]);
    le.push_back(str[i]);
    return printPath(i+1, j);
  } else if (c2 == ans) {
    ri.push_front(str[j]);
    le.push_back(str[j]);
    return printPath(i, j-1);
  } else {
    cerr << "ERRRRRRRROR";
    exit(-1);
  }
}

int main() {
  fastIO;
  // freopen("input.in", "rt", stdin);//  freopen("output.in", "wt", stdout);
  while (cin >> str) {
    clr(mem, -1);
    le.clear();
    ri.clear();
    idx = 0;
    cout << DP(0, str.size() - 1);
    printPath(0, str.size() - 1);
    cout << ' ';
    for(char c: le)
      cout << c;
    for(char c: ri)
      cout << c;
    cout << '\n';
  }
  return 0;
}

