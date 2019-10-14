#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
void debug() {
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifdef LOCAL
  freopen("input.in", "rt", stdin);
  //  freopen("output.txt", "wt", stdout);
#endif
}
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e2 + 9, OO = 1e9;

int arr[N];

int main() {
  debug();
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  int ans = -OO;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int total = 0, req = m;
      vector<int> A, B;
      for (int k = i; k <= j; ++k) {
        total += arr[k];
        A.push_back(arr[k]);
      }
      for (int k = 0; k < i; ++k)
        B.push_back(arr[k]);
      for (int k = j + 1; k < n; ++k)
        B.push_back(arr[k]);
      sort(A.begin(), A.end());
      sort(B.rbegin(), B.rend());
      int ptr1 = 0, ptr2 = 0;
      while (req && ptr1 < (int) A.size() && ptr2 < (int) B.size() && A[ptr1] < B[ptr2]) {
        total += B[ptr2] - A[ptr1];
        --req;
        ++ptr1, ++ptr2;
      }
      ans = max(ans, total);
    }
  }
  cout << ans;
  return 0;
}
