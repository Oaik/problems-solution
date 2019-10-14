#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 4e5 + 9, OO = 1e9 + 9;

vector<int> vec;
char arr[209][209];
int a, b, c, d, n, x, cur = 0;

void path1() {
  for (int i = 0; i < c  && cur != (int)vec.size(); ++i) {
    if (i & 1) {
      for (int j = 0; j < a && cur != (int)vec.size(); ++j) {
        if(arr[i][j] == '?')
          continue;
        arr[i][j] = 'a' + cur;
        --vec[cur];
        if(vec[cur] == 0) {
          ++cur;
        }
      }
    } else {
      for (int j = a - 1; j >= 0 && cur != (int)vec.size(); --j) {
        if(arr[i][j] == '?')
          continue;
        arr[i][j] = 'a' + cur;
        --vec[cur];
        if(vec[cur] == 0) {
          ++cur;
          if(cur == (int)vec.size())
            break;
        }
      }
    }
  }
}

void path2() {
  for (int i = 0; i < c && cur != (int)vec.size(); ++i) {
    if (i & 1) {
      for (int j = a - 1; j >= 0 && cur != (int)vec.size(); --j) {
        if(arr[i][j] == '?')
          continue;
        arr[i][j] = 'a' + cur;
        --vec[cur];
        if(vec[cur] == 0) {
          ++cur;
          if(cur == (int)vec.size())
            break;
        }
      }
    } else {
      for (int j = 0; j < a && cur != (int)vec.size(); ++j) {
        if(arr[i][j] == '?')
          continue;
        arr[i][j] = 'a' + cur;
        --vec[cur];
        if(vec[cur] == 0) {
          ++cur;
          if(cur == (int)vec.size())
            break;
        }
      }
    }
  }
}

int main() {
  fastIO;
  cin >> a >> b >> c >> d >> n;
  clr(arr, '?');

  for (int i = 0; i < b; ++i) {
    for (int j = 0; j < a; ++j) {
      arr[i][j] = '*';
    }
  }

  for (int i = 0; i < d; ++i) {
    for (int j = 0; j < c; ++j) {
      arr[i][j + a] = '*';
    }
  }

  for (int i = 0; i < n; ++i) {
    cin >> x;
    vec.push_back(x);
  }
  a += c;
  c = max(b, d);

  int dir = (min(b, d) & 1) ? 1 : 0;
  int dir2 = (arr[c-1][0] == '?') ? 1 : 0;
  if(!dir && !dir2) {
    path2();
  } else if(!dir && dir2) {
    path1();
  } else if(dir && dir2) {
    path2();
  } else {
    path1();
  }

  int rem = 0;
  for (int i = 0; i < n; ++i)
    rem += vec[i];
  if(rem > 0) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 0; i < c; ++i) {
      for (int j = 0; j < a; ++j) {
        if(arr[i][j] == '?' || arr[i][j] == '*')
          arr[i][j] = '.';
        cout << arr[i][j];
      }
      cout << '\n';
    }
  }
  return 0;
}
