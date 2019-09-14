#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 2e5 + 2, OO = 1e9 + 9, MOD = 1e9 + 7;

int arr[N];

int main() {
//  fastIO
//  read
  int n, idx = 1;
  while (scanf("%d", &n) != -1) {
    int steps = 0;
    set<int> st;
    for (int i = 0; i < n; ++i) {
      scanf("%d", arr + i);
      if (!arr[i]) {
        st.clear();
        continue;
      }
      if (st.find(arr[i]) != st.end()) {
        auto it = st.find(arr[i]);
        ++it;
        st.erase(it, st.end());
      } else {
        st.insert(arr[i]);
        auto it = st.find(arr[i]);
        ++it;
        st.erase(it, st.end());
        ++steps;
      }
    }
    printf("Case %d: %d\n", idx++, steps);
  }
  return 0;
}

