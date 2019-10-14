#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout << fixed << setprecision(0)
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e6 + 9, OO = 1e9, v = 1e6;
int arr[26][26];

int hold;
void holdit() {
  if (hold < 1 || hold > 9)
    hold = 10;
}

int main() {
  fastIO;
//  freopen("input.in", "rt", stdin); // freopen("output.in", "wt", stdout);
  char c, a;
  vector<pair<char, char>> vec;
  cin >> c >> a;
  arr[a - 'a'][c - '0']++;
  vec.push_back( { a, c });
  cin >> c >> a;
  arr[a - 'a'][c - '0']++;
  vec.push_back( { a, c });
  cin >> c >> a;
  arr[a - 'a'][c - '0']++;
  vec.push_back( { a, c });
  sort(all(vec));
  int ans = 3, cnt = 0;
  for (int i = 0; i < 26; ++i)
    ans = min(3 - *max_element(arr[i], arr[i] + 26), ans);
  for (int i = 0; i < 3; ++i) {
    cnt = 1;
    hold = vec[i].second - '0' + 1;
    holdit();
    if (arr[vec[i].first - 'a'][hold]) {
      cnt = 2;
      ans = min(ans, 3 - cnt);
      hold = vec[i].second - '0' + 2;
      holdit();
      if (arr[vec[i].first - 'a'][hold])
        cnt = 3, ans = min(ans, 3 - cnt);
      hold = vec[i].second - '0' - 1;
      holdit();
      if (arr[vec[i].first - 'a'][hold])
        cnt = 3, ans = min(ans, 3 - cnt);
    } else {
      ans = min(ans, 3 - cnt);
      hold = vec[i].second - '0' + 2;
      holdit();
      if (arr[vec[i].first - 'a'][hold])
        cnt = 2, ans = min(ans, 3 - cnt);
      hold = vec[i].second - '0' - 1;
      holdit();
      if (arr[vec[i].first - 'a'][hold])
        cnt = 2, ans = min(ans, 3 - cnt);
    }
    cnt = 1;
    hold = vec[i].second - '0' - 1;
    holdit();
    if (arr[vec[i].first - 'a'][hold]) {
      cnt = 2;
      ans = min(ans, 3 - cnt);
      hold = vec[i].second - '0' - 2;
      holdit();
      if (arr[vec[i].first - 'a'][hold])
        cnt = 3, ans = min(ans, 3 - cnt);
      hold = vec[i].second - '0' + 1;
      holdit();
      if (arr[vec[i].first - 'a'][hold])
        cnt = 3, ans = min(ans, 3 - cnt);
    } else {
      ans = min(ans, 3 - cnt);
      hold = vec[i].second - '0' - 2;
      holdit();
      if (arr[vec[i].first - 'a'][hold])
        cnt = 2, ans = min(ans, 3 - cnt);
      hold = vec[i].second - '0' + 1;
      holdit();
      if (arr[vec[i].first - 'a'][hold])
        cnt = 2, ans = min(ans, 3 - cnt);
    }
  }
  cout << ans;
  return 0;
}
