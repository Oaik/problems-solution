#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e6 + 9, OO = 1e9;

typedef complex<double> point;
#define X real()
#define Y imag()
#define cp(a,b)                 ( (conj(a)*(b)).imag() )  // a*b sin(T), if zero -> parllel
bool isCollinear(point a, point b, point c) {
  return fabs( cp(b-a, c-a) ) < EPS;
}

point arr[N];

int main() {
  fastIO;
//  read;
  int t;
  cin >> t;
  string str, str1;
  cin.ignore();
  getline(cin, str);
  while(t--) {
    int idx = 0;
    while(getline(cin, str), !str.empty() && !cin.eof()) {
      stringstream ss;
      ss << str;
      str.clear();
      int x = 0;
      int y = 0;
      bool enn = 0;
      while(ss >> str) {
        if(enn)
          y = stoi(str);
        else
          x = stoi(str);
        enn = 1;
      }
      point P(x, y);
      arr[idx++] = P;
    }
    int cnt = 0, mx = 0;
    for (int i = 0; i < idx; ++i) {
      for (int j = i + 1; j < idx; ++j) {
        cnt = 0;
        for (int k = j+1; k < idx; ++k) {
          if(isCollinear(arr[i], arr[j], arr[k]))
            ++cnt;
        }
        mx = max(cnt, mx);
      }
    }
    cout << mx << '\n';
    if(t)
      cout << '\n';
  }
  return 0;
}

