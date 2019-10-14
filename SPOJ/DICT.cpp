#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 19, M = 1e5 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 2e18;

vector<vector<int>> trie;
vector<bool> isEnd;

int addTrie() {
  trie.push_back(vector<int>(28, -1));
  isEnd.push_back(0);
  return isEnd.size() - 1;
}

void insert(string str) {
  int cur = 0;
  for (int i = 0; i < (int) str.size(); ++i) {
    int word = str[i] - 'a';
    int nxt = trie[cur][word];
    if (nxt == -1)
      nxt = addTrie();
    trie[cur][word] = nxt;
    cur = nxt;
  }
  isEnd[cur] = 1;
}

vector<string> ans;

void rec(int cur, string str) {
  for (int i = 0; i < 26; ++i) {
    int nxt = trie[cur][i];
    if(nxt != -1) {
      str.push_back(i + 'a');
      if(isEnd[nxt])
        ans.push_back(str);
      rec(nxt, str);
      str.pop_back();
    }
  }
}

bool isPre(string str) {
  int cur = 0;
  for (int i = 0; i < (int)str.size(); ++i) {
    int word = str[i] - 'a';
    int nxt = trie[cur][word];
    if(nxt == -1)
      return 0;
    cur = nxt;
  }
  bool can = 0;
  for (int i = 0; i < 26; ++i) {
    if(trie[cur][i] != -1)
      can = 1;
  }
  if(!can)
    return can;
  rec(cur, str);
  return can;
}


int main() {
  fastIO;
  addTrie();
  int n;
  cin >> n;
  string str;
  for (int i = 0; i < n; ++i) {
    cin >> str;
    insert(str);
  }
  cin >> n;
  for (int i = 0; i < n; ++i) {
    ans.clear();
    cin >> str;
    cout << "Case #" << i + 1 << ":\n";
    if(!isPre(str))
      cout << "No match.\n";
    else
      for(string ss: ans)
        cout << ss << '\n';
  }
  return 0;
}

