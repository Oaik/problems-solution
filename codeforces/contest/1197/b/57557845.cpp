#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(10), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9;

int arr[N];

int main() {
  fastIO;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  int ptr1, ptr2, idx, mx = 0;
  for (int i = 0; i < n; ++i)
    if(arr[i] > mx)
      mx = arr[i], idx = i;
  ptr1 = idx - 1, ptr2 = idx + 1;
  bool can = 1;
  while(ptr1 >= 0 || ptr2 < n) {
    if(ptr1 < 0) {
      if(arr[ptr2] < mx) {
        mx = arr[ptr2];
        ++ptr2;
      } else {
        can = 0;
        break;
      }
    } else if(ptr2 >= n) {
      if(arr[ptr1] < mx) {
        mx = arr[ptr1];
        --ptr1;
      } else {
        can = 0;
        break;
      }
    } else {
      if(arr[ptr1] > arr[ptr2]) {
        if(arr[ptr1] < mx) {
          mx = arr[ptr1];
          --ptr1;
        } else {
          can = 0;
          break;
        }
      } else {
        if(arr[ptr2] < mx) {
          mx = arr[ptr2];
          ++ptr2;
        } else {
          can = 0;
          break;
        }
      }
    }
  }
  if(can)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
