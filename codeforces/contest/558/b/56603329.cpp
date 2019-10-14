#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
const int N = 1e6 + 9, OO = 2e9;

int arr[N], firstApp[N],lastApp[N] ,freq[N];
vector<pair<int, pair<int, int>>> vec;

int main() {
  debug();
  int n, a, mx = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    if(!firstApp[arr[i]])
      firstApp[arr[i]] = i + 1;
    lastApp[arr[i]] = i + 1;
    ++freq[arr[i]];
    mx = max(mx, freq[arr[i]]);
  }
  for (int i = 1; i < N; ++i) {
    if(freq[i] == mx) {
      vec.push_back({lastApp[i] - firstApp[i] + 1, {firstApp[i], lastApp[i]}});
    }
  }
  sort(all(vec));
  cout << vec[0].second.first << ' ' << vec[0].second.second;
  return 0;
}
