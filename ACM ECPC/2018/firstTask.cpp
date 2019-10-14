#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("task.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 3e4 + 9, OO = 1e9 + 1, MOD = 1e9 + 7;
const ll inf = 1e18;
 
int arr[N];
 
int main() {
//  fastIO
  read
  int t, n;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    set<int> st;
    for (int i = 0; i < n; ++i) {
      scanf("%d", arr + i);
      st.insert(arr[i]);
    }
//    sort(arr, arr + n);
    int best = OO + OO;
    int idx = 1;
    for(int it: st) { // let it is the maximum number in the permutation
      int cur = ((int)st.size()) - idx; // remove all values which is greater than it
      cur += n - ((int)st.size()); // remove all duplicates
      cur += (it - idx); // adding missing values between 1 and it
 
      best = min(cur, best);
      ++idx;
    }
    int best2 = n + 1;
    if(*st.begin() == 1)
      --best2;
    printf("%d\n", min(best, best2));
  }
  return 0;
}
