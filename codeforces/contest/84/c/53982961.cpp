#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
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
const int N = 1e5 + 9, OO = 1e9;

vector<pair<int, int>> vec;
vector<pair<pair<int, int>, int>> idxVec;
int ans[N];

int main() {
  debug();
  int n, x, r, y, m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> x >> r;
    vec.push_back({x, r});
    idxVec.push_back({{x, r}, i});
  }
  sort(all(vec));
  sort(all(idxVec));
  cin >> n;
  clr(ans, -1);
  ll dist, rr;
  int total = 0;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    auto it = lower_bound(vec.begin(), vec.end(), make_pair(x, 0));
    int s = -1, f = -1;
    if(it == vec.end()) {
      f = vec.size() - 1;
      int idxFF = idxVec[f].second;
      if(f != -1 && ans[idxFF] == -1) {
        dist = (ll)(x - vec[f].first) * (ll)(x - vec[f].first) + (ll)(y) * (ll)(y);
        rr = (ll)vec[f].second * (ll)vec[f].second;
        if(dist <= rr) {
          ans[idxFF] = i + 1;
          ++total;
        }
      }
      continue;
    }
    s = it - vec.begin();
    int idxF, idxS = idxVec[s].second;
    if(s != 0) {
      f = s - 1;
      idxF = idxVec[f].second;
    }
    if(ans[idxS] == -1) {
      dist = (ll)(x - vec[s].first) * (ll)(x - vec[s].first) + (ll)(y) * (ll)(y);
      rr = (ll)vec[s].second * (ll)vec[s].second;
      if(dist <= rr) {
        ans[idxS] = i + 1;
        ++total;
      }
    }
    if(f != -1 && ans[idxF] == -1) {
      dist = (ll)(x - vec[f].first) * (ll)(x - vec[f].first) + (ll)(y) * (ll)(y);
      rr = (ll)vec[f].second * (ll)vec[f].second;
      if(dist <= rr) {
        ans[idxF] = i + 1;
        ++total;
      }
    }
  }
  cout << total << endl;
  for (int i = 0; i < m; ++i) {
    cout << ans[i] << " ";
  }
}
