#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
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
const int N = 2e5 + 9, OO = 2e9 + 9;

multiset<int> st;
int main() {
  debug();
  int n, a;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    st.insert(a);
  }
  int cnt = 0;
  for (int i = 1; i < N; ++i) {
    auto it = st.lower_bound(i);
    if(it == st.end())
      break;
    ++cnt;
    st.erase(it);
  }
  cout << cnt;
}