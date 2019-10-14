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

vector<int> diff, sim;
string str1, str2, res;

void mo5tlf(int idx = 0) {
  if (str1[idx] != 'a' && str2[idx] != 'a')
    res[idx] = 'a';
  else if (str1[idx] != 'b' && str2[idx] != 'b')
    res[idx] = 'b';
  else
    res[idx] = 'c';
}

int main() {
  debug();
  int n, t;
  cin >> n >> t;
  cin >> str1 >> str2;
  res = str1;
  for (int i = 0; i < n; ++i) {
    if (str1[i] == str2[i])
      sim.push_back(i);
    else
      diff.push_back(i);
  }
  if ((int) (diff.size()) & 1) {
    --t;
    mo5tlf(diff[0]);
  }
  for (int i = (int) (diff.size()) & 1; i < (int) diff.size(); i += 2) {
    int rem = (int) (diff.size()) - i;
    if (t < rem) {
      res[diff[i]] = str1[diff[i]];
      res[diff[i+1]] = str2[diff[i + 1]];
      --t;
    } else {
      mo5tlf(diff[i]);
      mo5tlf(diff[i + 1]);
      t -= 2;
    }
  }
  for (int i = 0; i < (int) sim.size(); ++i) {
    if (t > 0) {
      --t;
      mo5tlf(sim[i]);
    } else {
      res[sim[i]] = str1[sim[i]];
    }
  }
  if (t != 0) {
    cout << -1;
  } else {
    cout << res;
  }
}
