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
set<string> st;
map<string, int> mp;
vector<pair<int, string>> vec;
unordered_map<string, bool> vis;

bool cmp(pair<int, string> left, pair<int, string> right) {
  if(left.first == right.first)
    return left.second < right.second;
  return left.first > right.first;
}
int main() {
  debug();
  string myname, from, to, type, ff;
  cin >> myname;
  int n, a;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> from >> type;
    if(type != "likes")
      cin >> ff;
    cin >> to >> ff;
    to = to.substr(0, to.size() - 2);
    st.insert(from);
    st.insert(to);
    if(type == "posted")
      a = 15;
    else if(type == "commented")
      a = 10;
    else
      a = 5;
    if(to == myname) {
      mp[from] += a;
    } else if(from == myname) {
      mp[to] += a;
    }
  }
  for(auto it: mp) {
    vec.push_back({it.second, it.first});
  }
  sort(all(vec), cmp);
  for(auto it: vec) {
    if(it.second == myname)
      continue;
    cout << it.second << endl;
    vis[it.second] = 1;
  }
  for(auto it: st) {
    if(!vis[it]) {
      if(it == myname)
        continue;
      vis[it] = 1;
      cout << it << endl;
    }
  }
}
