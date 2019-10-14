#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 1e2 + 9, OO = 1e9;

int arr[N];
set<int> st;
vector<int> vec;
map<int, int> mp;

int main() {
//  fastIO;
  int n, x;
  ll k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    ++mp[x];
    arr[i] = x;
    st.insert(x);
  }
  for(int it: st)
    vec.push_back(it);
  sort(arr, arr + n);
  for (int i = 0; i < (int)vec.size(); ++i) {
    if((ll)n * (ll)mp[vec[i]] >= k) {
      int last = (k-1) / mp[vec[i]];
      cout << vec[i] << ' ' << arr[last];
      return 0;
    } else {
      k -= (ll)n * (ll)mp[vec[i]];
    }
  }
  return 0;
}
