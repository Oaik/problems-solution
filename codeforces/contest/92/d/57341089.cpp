#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define readIn freopen("input.in", "rt", stdin);
#define writeOut freopen("output.in", "wt", stdout);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, OO = 1e9;

vector<pair<int, int>> vec;
int arr[N];

int main() {
  fastIO;
  int n, a;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    vec.push_back({a, i});
  }
  sort(all(vec));
  int ptr = 0;
  for(pair<int, int> it: vec) {
    if(it.second > ptr)
      arr[it.second] = -1;
    else
      arr[it.second] = ptr - it.second - 1;
    ptr = max(ptr, it.second);
  }
  for (int i = 0; i < n; ++i)
    cout << arr[i] << ' ';
  return 0;
}
