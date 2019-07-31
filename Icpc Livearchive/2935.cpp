#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);odeforces.comodeforces.com
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 3e5 + 9, M = 1e2 + 9, OO = 1e9;
vector<vector<int>> adj;

string canoincal(int x, int par) {
  vector<string> children;
  for(auto it: adj[x]) {
    if(it != par)
      children.push_back(canoincal(it, x));
  }
  string ans = "(";
  sort(all(children));
  if(children.size()) {
    for(string it:children)
      ans += it;
  }
  ans += ")";
  return ans;
}

int main() {
  fastIO;
  int t;
  cin >> t;
  string str1, str2;
  while(t--) {
    cin >> str1 >> str2;
    priority_queue<int> q;
    adj = vector<vector<int>>(str1.size() + 1);
    int cur = 1, ptr = 0;
    for(auto c: str1) {
      if(c == '0') {
        adj[ptr].push_back(cur);
        q.push(ptr);
        ptr = cur;
        ++cur;
      } else {
        ptr = q.top();
        q.pop();
      }
    }
    string cmp1 = canoincal(0, -1);
    priority_queue<int> qq;
    adj = vector<vector<int>> (str2.size() + 1);
    cur = 1, ptr = 0;
    for(auto c: str2) {
      if(c == '0') {
        adj[ptr].push_back(cur);
        q.push(ptr);
        ptr = cur;
        ++cur;
      } else {
        ptr = q.top();
        q.pop();
      }
    }
    string cmp2 = canoincal(0, -1);
    if(cmp1 == cmp2)
      cout << "same\n";
    else
      cout << "different\n";
  }
  return 0;
}

