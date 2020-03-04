#include<bits/stdc++.h>
using namespace std;
#define ll long long
double const EPS = 1e-9, PI = acos(-1);
const int N = 3e5 + 9, M = 2e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

vector<vector<int>> tree;
vector<int> cnt;
string str[N], aa;

void clear() {
  tree.clear();
  cnt.clear();
}

int add() {
  tree.push_back(vector<int>(26, -1));
  cnt.push_back(1);
  return cnt.size() - 1;
}

void insert(string str) {
  int cur = 0;
  for (int i = 0; i < (int)str.size(); ++i) {
    int nxt = tree[cur][str[i] - 'a'];
    if(nxt == -1)
      nxt = add();
    else
      cnt[nxt]++;
    tree[cur][str[i] - 'a'] = nxt;
    cur = nxt;
  }
}

int search(string str) {
  int mx = OO, ans = 0, cur = 0;
  for (int i = 0; i < (int)str.size(); ++i) {
    int nxt = tree[cur][str[i]-'a'];
    if(nxt == -1)
      break;
    mx = min(mx - 1, cnt[nxt] - 1);
    cur = nxt;
    ++ans;
    if(mx == 0) return ans;
  }
  return ans;
}

int main() {
  cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
//  freopen("input.in", "rt", stdin);
  while(cin >> n >> m) {
    clear();
    add();
    for (int i = 0; i < n; ++i)
      cin >> str[i];
    for (int i = 0; i < m; ++i) {
      cin >> aa;
      insert(aa);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
      ans += search(str[i]);
    cout << ans << '\n';
  }
  return 0;
}

