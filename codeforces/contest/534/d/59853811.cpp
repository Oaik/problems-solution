#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, M = 2e5 + 2, OO = 1e9 + 9, MOD = 1e9 + 7;

int freq[N];
vector<int> ans;
vector<int> vv[N];

int main() {
  fastIO
  int n, a;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    ++freq[a];
    vv[a].push_back(i + 1);
  }
  int cur = 0;
  while(1) {
    if(freq[cur]) {
      --freq[cur];
      ans.push_back(cur);
      ++cur;
    } else {
      int temp = cur;
      bool en = 0;
      while(temp >= 0) {
        temp -= 3;
        if(temp < 0)
          break;
        if(freq[temp]) {
          --freq[temp];
          ans.push_back(temp);
          cur = temp + 1;
          en = 1;
          break;
        }
      }
      if(!en)
        break;
    }
  }
  for (int i = 0; i < n; ++i) {
    if(freq[i]) {
      cout << "Impossible\n";
      return 0;
    }
  }
  cout << "Possible\n";
  for(int it: ans) {
    cout << vv[it].back() << ' ';
    flush(cout);
    vv[it].pop_back();
  }
  return 0;
}
