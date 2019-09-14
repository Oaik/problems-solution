#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e6 + 9, M = 2e6 + 1, OO = 1e9 + 1, MOD = 1e9 + 7;
const unsigned ll inf = 9e18;

char arr[12][12], req[12][12], temp[12][12], tt[12], tany[12][12];
int n, deg[3] = {90, 180, 270};

void rotate90() {

  for (int i = n - 1; i >= 0; --i) {
    int it = 0;
    for (int j = n - 1; j >= 0; --j)
      tt[it++] = arr[j][i];
    for (int j = 0; j < n; ++j)
      temp[i][j] = tt[j];
  }

}

void rotate90Tany() {

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      tany[i][j] = temp[i][j];

  for (int i = n - 1; i >= 0; --i) {
    int it = 0;
    for (int j = n - 1; j >= 0; --j)
      tt[it++] = tany[j][i];
    for (int j = 0; j < n; ++j)
      temp[i][j] = tt[j];
  }

}

void reflectVe() {

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      temp[i][j] = arr[i][j];
  for (int i = 0; i < n / 2; ++i)
    swap(temp[i], temp[n - i - 1]);

}

bool check() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (temp[i][j] != req[i][j])
        return 0;
  return 1;
}

int main() {
  fastIO
  int idx = 1;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        cin >> arr[i][j];
      for (int j = 0; j < n; ++j)
        cin >> req[i][j];
    }
    bool pres = 1;
    for (int i = 0; i < n && pres; ++i) {
      for (int j = 0; j < n && pres; ++j) {
        if (arr[i][j] != req[i][j]) {
          pres = 0;
          break;
        }
      }
    }
    if (pres) {
      cout << "Pattern " << idx++ << " was preserved." << endl;
      continue;
    }
    for (int i = 0; i < 3; ++i) {
      if(i == 0)
        rotate90();
      else
        rotate90Tany();
      if (check()) {
        cout << "Pattern " << idx++ << " was rotated " << deg[i] << " degrees." << endl;
        pres = 1;
        break;
      }
    }
    if (pres)
      continue;
    reflectVe();
    if(check()) {
      cout << "Pattern " << idx++ << " was reflected vertically." << endl;
      pres = 1;
      continue;
    }
    for (int i = 0; i < 3; ++i) {
      rotate90Tany();
      if(check()) {
        cout << "Pattern " << idx++ << " was reflected vertically and rotated " << deg[i] << " degrees." << endl;
        pres = 1;
        continue;
      }
    }
    if (pres)
      continue;
    cout << "Pattern " << idx++ <<" was improperly transformed." << endl;
  }
  return 0;
}

