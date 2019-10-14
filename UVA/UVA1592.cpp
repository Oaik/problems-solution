#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin)
#define write freopen("output.in", "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e4 + 9, M = 3e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;

string arr[N][10];
map<string, vector<int>[11]> mp;

int main() {
  fastIO;
//  read;
  int n, m;
  string str;
  while(getline(cin, str)) {
    mp.clear();
    stringstream ss(str);
    int k = 0;
    while(ss >> str) {
      if(!k)
        n = stoi(str);
      else
        m = stoi(str);
      ++k;
    }
    bool can = 1;
    int r1 = -1, r2 = -1, c1 = -1,c2 = -1;
    for (int i = 0; i < n; ++i) {
      map<int, int> maa;
      getline(cin, str);
      string temp;
      int j = 0, mx = 0, rr = -1, cnt = 0;
      while(cnt < m && can) {
        if(str[j] == ',' || j == (int)str.size()) {
          arr[i][cnt] = temp;
          for(auto it: mp[temp][cnt]) {
            ++maa[it];
            if(maa[it] > mx) {
              rr = it;
              mx = maa[it];
            }
          }
          mp[temp][cnt].push_back(i);
          temp.clear();
          ++cnt;
        } else {
          temp.push_back(str[j]);
        }
        ++j;
      }
      if(mx > 1) {
        can = 0;
        r2 = i;
        r1 = rr;
        for (int j = 0; j < m; ++j) {
          if(c1 != -1 && c2 != -1)
            break;
          if(arr[r1][j] != arr[r2][j])
            continue;
          if(c1 == -1) {
            c1 = j;
            continue;
          }
          if(c2 == -1)
            c2 = j;
        }
      }
    }
    if(can)
      cout << "YES";
    else
      cout << "NO\n" << r1 + 1 << ' ' << r2 + 1 << '\n' << c1 + 1 << ' ' << c2 + 1;
    cout << endl;
  }
  return 0;
}

