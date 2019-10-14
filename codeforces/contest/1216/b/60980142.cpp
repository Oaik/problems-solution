#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
const int M = 1e5 + 2;

vector<pair<int, int>> aa;
int vv[M];

int main() {
  fastIO;
  int n, cc;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> cc;
    aa.push_back({cc, i});
  }
  ll total = 0, iii = 0;
  sort(aa.rbegin(), aa.rend());
  for(pair<int, int> jj: aa) {
    total += (iii) * jj.first + 1;
    vv[iii++] = jj.second;
  }
  cout << total << '\n';
  for (int i = 0; i < n; ++i)
    cout << vv[i] + 1 << ' ';
  return 0;
}
