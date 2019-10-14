#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cout << fixed << setprecision(0)
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, OO = 1e9, v = 1e6;

int arr[N];

int main() {
  fastIO;
//  freopen("input.in", "rt", stdin); // freopen("output.in", "wt", stdout);
  int n, m, a, b, c;
  cin >> n >> m;
  --m;
  cin >> a >> b >> c;
  arr[a] = 1, arr[b] = 2, arr[c] = 3;
  int cur;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    if(arr[a]) {
      cur = arr[a];
      arr[b] = (cur + 1) % 3;
      arr[c] = (cur + 2) % 3;
      if(!arr[b]) arr[b] = 3;
      if(!arr[c]) arr[c] = 3;
    }
    else if(arr[b]){
      cur = arr[b];
      arr[a] = (cur + 1) % 3;
      arr[c] = (cur + 2) % 3;
      if(!arr[a]) arr[a] = 3;
      if(!arr[c]) arr[c] = 3;
    }
    else if(arr[c]){
      cur = arr[c];
      arr[a] = (cur + 1) % 3;
      arr[b] = (cur + 2) % 3;
      if(!arr[a]) arr[a] = 3;
      if(!arr[b]) arr[b] = 3;
    } else
      arr[a] = 1, arr[b] = 2, arr[c] = 3;
  }
  for (int i = 1; i <= n; ++i)
    cout << arr[i] << ' ';
  return 0;
}
