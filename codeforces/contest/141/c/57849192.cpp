#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 3e3 + 9, OO = 1e9;

multiset<int> st;
map<string, int> mp;
vector<int> elm[N];
vector<string> vec[N];
vector<pair<int, int>> ans;

int main() {
//  fastIO;
  int n, val, mx = 0;
  string str;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> str >> val;
    mp[str] = val;
    st.insert(val);
    mx = max(mx, val);
    vec[val].push_back(str);
  }
  set<int>::iterator it;
  for (int i = 0; i < n; ++i) {
    it = st.lower_bound(i);
    if(it != st.end())
      val = *it;
    if (it == st.end() || val > i ) {
      if(it == st.begin()) {
        cout << -1;
        return 0;
      }
      --it;
      val = *it;
      if(val > i) {
        cout << -1;
        return 0;
      }
      elm[val].push_back(i);
      st.erase(it);
    } else {
      val = *it;
      elm[val].push_back(i);
      st.erase(it);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (int)elm[i].size(); ++j)
      ans.push_back({elm[i][j], i});
  }
  sort(all(ans));
  for (int i = 0; i < n; ++i) {
    val = vec[ans[i].second].size();
    cout << vec[ans[i].second][val - 1] << ' ' << 3000 - ans[i].second << '\n';
    vec[ans[i].second].pop_back();
  }
}
