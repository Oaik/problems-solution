#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e4 + 9, OO = 1e9;

int arr[N], freq[N];
vector<pair<int, int>> vec;

int main() {
  fastIO;
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    ++freq[arr[i]];
    vec.push_back({arr[i], i});
  }
  sort(freq, freq + N, greater<int>());
  sort(all(vec));
  int mx = freq[0], mx1 = freq[1];
  if((mx + mx1 < 4 && mx < 3) || n <= 2) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for(auto it: vec)
    cout << it.second << ' ';
  cout << '\n';
  int i = 1;
  for (; i < n; ++i) {
    if(vec[i].first == vec[i-1].first) {
      swap(vec[i], vec[i-1]);
      break;
    }
  }
  ++i;
  for(auto it: vec)
    cout << it.second << ' ';
  cout << '\n';
//  swap(vec[i], vec[i-1]);
  for (; i < n; ++i) {
    if(vec[i].first == vec[i-1].first) {
      swap(vec[i], vec[i-1]);
      break;
    }
  }
  for(auto it: vec)
    cout << it.second << ' ';
  cout << '\n';

  return 0;
}
