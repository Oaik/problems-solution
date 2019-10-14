#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "rt", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(2), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 1e6 + 1, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 2e18;

vector<vector<int>> tree;
vector<bool> isWord;
string arr[N];

int add() {
  tree.push_back(vector<int>(26, -1));
  isWord.push_back(0);
  return isWord.size() - 1;
}

void init() {
  tree.clear();
  isWord.clear();
  add();
}

void insert(string str) {
  int cur = 0;
  for (int i = 0; i < (int)str.size(); ++i) {
    int nxt = tree[cur][str[i] - 'a'];
    if(nxt == -1)
      nxt = add();
    tree[cur][str[i] - 'a'] = nxt;
    cur = nxt;
  }
  isWord[cur] = 1;
}

int rec(string str) {
  int cur = 0, total = 0;
  bool can = 0;
  for (int i = 0; i < (int)str.size(); ++i) {
    int rr = 0;
    for (int j = 0; j < 26; ++j) {
      if(tree[cur][j] != -1)
        ++rr;
    }
    int nxt = tree[cur][str[i] - 'a'];
    if((rr != 1 && can) || !can)
      ++total;
    if(isWord[nxt])
      can = 0;
    else
      can = 1;
    cur = nxt;
  }
  return total;
}

int main() {
  fastIO;
//  read("input.in");
//  write("output.in");
  int n;
  while(cin >> n) {
    init();
    string str;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      insert(arr[i]);
    }
    ll total = 0;
    for (int i = 0; i < n; ++i)
      total += rec(arr[i]);
    cout << 1.0 * total / n;
    cout << '\n';
  }
  return 0;
}

