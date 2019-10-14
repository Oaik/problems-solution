#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)    ((v).begin()),((v).end())
#define clr(a,b)  memset(a,b,sizeof(a))
const double EPS = 1e-8, pi = acos(-1);
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  // freopen("output.in", "wt", stdout);
#endif
}

int const N = 2e3 + 9, OO = 1e9;

int arr[N];
vector<int> vec;

int main() {
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  debug();
  ll sum = 0;
  int n, h, ans = 0, idx = 0;
  cin >> n >> h;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  for (int i = 0; i < n; ++i) {
    vec.clear();
    sum = 0;
    for (int j = 0; j <= i; ++j)
      vec.push_back(arr[j]);
    sort(all(vec), greater<int>());
    for (int i = 0; i < (int)vec.size(); ++i) {
      if((int)vec.size() > i+1) {
        sum += max(vec[i], vec[i+1]);
        ++i;
      } else
        sum += vec[i];
    }
    if(sum > h)
      break;
    if(sum >= ans) {
      ans = sum;
      idx = i;
    }
  }
  cout << idx + 1;
  return 0;
}
