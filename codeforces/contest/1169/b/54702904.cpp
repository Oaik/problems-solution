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
const int N = 1e5 + 9, OO = 1e9 + 9;

vector<pair<int, int>> vec;
set<int> st;

int main() {
  debug();
  int n, m, a, b;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    if (a > b)
      swap(a, b);
    vec.push_back( { a, b });
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < m; ++i) {
    if (st.find(vec[i].first) != st.end() || st.find(vec[i].second) != st.end())
      continue;
    st.insert(vec[i].first);
    st.insert(vec[i].second);
    if (st.size() >= 4)
      break;
  }
  bool can = 0;
  int idx = 0, idxD = 0;
  for (auto fst : st) {
    ++idx;
    for (auto snd : st) {
      can = 1, ++idxD;
      if (idxD < idx)
        continue;
      for (int k = 0; k < m; ++k) {
        if (!(vec[k].first == fst || vec[k].second == fst || vec[k].first == snd || vec[k].second == snd)) {
          can = 0;
          break;
        }
      }
      if (can) {
        cout << "YES\n";
        return 0;
      }
    }
    idxD = 0;
  }
  cout << "NO\n";
  return 0;
}
