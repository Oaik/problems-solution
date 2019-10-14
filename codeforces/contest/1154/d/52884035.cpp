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

int const N = 2e5 + 9, OO = 1e9;

bool arr[N];

int main() {
  debug();
  int n, b, a, tempa, cnt = 0;
  cin >> n >> b >> a;
  tempa = a;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  for (int i = 0; i < n; ++i) {
    if(arr[i] == 1) {
      if(tempa == a) {
        --tempa;
      } else if(b){
        --b;
        if(tempa < a)
          ++tempa;
      } else if(tempa) {
        --tempa;
      } else
        break;
      ++cnt;
    } else {
      if(tempa) {
        --tempa;
        ++cnt;
      } else if(b) {
        --b;
        ++cnt;
      } else
        break;
    }
  }
  cout << cnt;
  return 0;
}