#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "rt", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, M = 1e6 + 1, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 2e18;

vector<vector<int>> tree;
vector<bool> isWord;

int add() {
  tree.push_back(vector<int>(128, -1));
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
    int word = str[i];
    if(word == 92)
      word = 1;
    int nxt = tree[cur][word];
    if(nxt == -1)
      nxt = add();
    tree[cur][word] = nxt;
    cur = nxt;
    if(i + 1 < (int)str.size() && str[i + 1] == 92)
      isWord[cur] = 1;
  }
  isWord[cur] = 1;
}

void rec(int cur, string str, int depth = 0) {
//  if(str.empty()) {
//    for (int i = 0; i < depth; ++i)
//      cout << "  ";
//  }
  if(isWord[cur])
    cout << str << endl;
  for (int i = 0; i < 128; ++i) {
    int nxt = tree[cur][i];
    if(nxt != -1) {
      if(i == 1) {
        string rep(depth + 1, ' ');
        rec(nxt, rep, depth + 1);
      } else {
        str.push_back(i);
        rec(nxt, str, depth);
        str.pop_back();
      }
    }
  }
}

int main() {
  fastIO;
  int n;
  bool f = 0;
  while(cin >> n) {
    init();
    string str;
    if(!f) {
      f = 1;
      cin.ignore();
    } else {
      getline(cin, str);
    }
    for (int i = 0; i < n; ++i) {
      getline(cin, str);
      insert(str);
    }
    rec(0, "");
    cout << '\n';
  }

  return 0;
}

