#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(3), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
double const EPS = 1e-15, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e5;

vector<string> allElm, vec;
vector<pair<string, string>> res;
string str, str2;
map<pair<string, string>, bool> mp;

int main() {
  fastIO;
  int n, m, idx = 1;
  while(cin >> n, n) {
    allElm.clear();
    mp.clear();
    for (int i = 0; i < n; ++i) {
      cin >> m;
      vec.clear();
      for (int j = 0; j < m; ++j) {
        cin >> str;
        vec.push_back(str);
        allElm.push_back(str);
      }
      m = vec.size();
      for (int j = 0; j < m; ++j) {
        for (int k = j+1; k < m; ++k) {
          mp[{vec[j], vec[k]}] = 1;
//          mp[{vec[k], vec[j]}] = 1;
        }
      }
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> str >> str2;
      mp[{str, str2}] = 1;
//      mp[{str2, str}] = 1;
    }
    n = allElm.size();
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          mp[{allElm[i], allElm[j]}] |= (mp[{allElm[i], allElm[k]}] & mp[{allElm[k], allElm[j]}]);
        }
      }
    }
    int cnt = 0;
    res.clear();
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        if(!mp[{allElm[i], allElm[j]}] && !mp[{allElm[j], allElm[i]}]) {
          if(cnt < 2)
            res.push_back({allElm[i], allElm[j]});
          ++cnt;
        }
      }
    }
    if(cnt) {
      cout << "Case " << idx << ", " << cnt << " concurrent events:\n";
      cout << '(' << res[0].first << ',' << res[0].second << ')' << ' ';
      if((int)res.size() == 2)
        cout << '(' << res[1].first << ',' << res[1].second << ')' << ' ';
    } else {
      cout << "Case " << idx << ", no concurrent events.";
    }
    cout << endl;
    ++idx;
  }
  return 0;
}

