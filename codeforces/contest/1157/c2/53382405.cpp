#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  // freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int const N = 2e5 + 9, OO = 1e9;

int arr[N];
vector<char> vec;

int main() {
  debug();
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  int l = 0, r = n - 1, cur = -1;
  while (l <= r) {
    if (arr[l] == arr[r] && arr[l] > cur)  {
      int rr1 = 1, ll1 = 1;
      for (int j = l+1; j < r; ++j) {
        if(arr[j] > arr[j-1])
          ++ll1;
        else
          break;
      }
      for (int j = r-1; j > l; --j) {
        if(arr[j] > arr[j+1])
          ++rr1;
        else
          break;
      }
      if(rr1 > ll1) {
        while(rr1--)
          vec.push_back('R');
      } else {
        while(ll1--)
          vec.push_back('L');
      }
      break;
    }
    if ((arr[l] < arr[r] && arr[l] > cur)) {
      vec.push_back('L');
      cur = arr[l];
      ++l;
      continue;
    } else if (arr[r] > cur) {
      vec.push_back('R');
      cur = arr[r];
      --r;
      continue;
    } else if (arr[l] > cur) {
      vec.push_back('L');
      cur = arr[l];
      ++l;
      continue;
    }
    break;
  }
  cout << vec.size() << endl;
  for (char c : vec) {
    cout << c;
  }
}
