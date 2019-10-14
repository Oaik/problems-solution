#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define rall(v) ((v).rbegin()),((v).rend())
#define read(v) freopen(v, "rt", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(2), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 1e6 + 1, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e16;

int a, n, w, arr[N];

bool can(int mid) {
  int ptr1 = 0;
  int total = w;
  while(ptr1 < n && total) {
    --total;
    ptr1 = lower_bound(arr, arr + n, arr[ptr1] + mid) - arr;
  }
  if(!total)
    return 1;
  return 0;
}

int main() {
  fastIO;
//  read("input.in");
//  write("output.in");
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> w;
    vector<int> vec;
    for (int i = 0; i < n; ++i)
      cin >> arr[i];
    sort(arr, arr + n);
    int start = 1, end = 1e9 + 1, mid, ans;
    while(start <= end) {
      mid = start + (end - start)/ 2;
      if(can(mid)) {
        start = mid + 1;
        ans = mid;
      } else {
        end = mid - 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}

