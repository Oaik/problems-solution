#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define all(v)    ((v).begin()),((v).end())
#define clr(a,b)  memset(a,b,sizeof(a))
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);
// freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int const N = 1e9 + 9, OO = 1e9;

int arr[109];

vector<int> vec;

int main() {
  debug();
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  int d = 0, cnt = 0;
  for (int i = 1; i < 101; ++i) {
    d = 0, cnt = 0;
    for (int j = 0; j < n; ++j) {
      if(arr[j] == i) {
        ++cnt;
        continue;
      }
      if(arr[j] > i) {
        if(d == 0) {
          d = arr[j] - i;
        } else {
          if(d != arr[j] - i)
            break;
        }
        ++cnt;
      } else {
        if(d == 0) {
          d = i - arr[j];
        } else {
          if(d != i - arr[j])
            break;
        }
        ++cnt;
      }
    }
    if(cnt == n)
      vec.push_back(d);
  }
  sort(all(vec));
  if(vec.size() == 0)
    cout << -1;
  else
    cout << vec[0];
  return 0;
}