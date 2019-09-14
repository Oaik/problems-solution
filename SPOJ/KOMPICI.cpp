#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e6 + 9, M = 3e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

map<int, int> mp;
vector<pair<int, int>> vec;

int main() {
  fastIO;
  int n;
  cin >> n;
  string str;
  for (int i = 0; i < n; ++i) {
    cin >> str;
    set<int> st;
    for(char c: str)
      st.insert(c - '0');
    int num = 0;
    for(int it: st)
      num = num | (1 << it);
    ++mp[num];
  }
  for(auto it: mp)
    vec.push_back({it.first, it.second});
  ll sum = 0;
  n = vec.size();
  for (int i = 0; i < n; ++i) {
    sum += ((ll)vec[i].second * (vec[i].second-1)) / 2;
    for (int j = i+1; j < n; ++j) {
      if(vec[i].first & vec[j].first)
        sum += (ll)vec[i].second * vec[j].second;
    }
  }
  cout << sum;
  return 0;
}

