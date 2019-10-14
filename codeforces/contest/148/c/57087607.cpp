#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e6 + 9, OO = 1e9;

int main() {
  fastIO;
  // freopen("input.in", "rt", stdin);//  freopen("output.in", "wt", stdout);
  int n, a, b, nn;
  cin >> n >> a >> b;
  vector<int> v;
  nn = n;
  v.push_back(1);
  n -= 1;
  int res = 1;
  for (int i = 1; i <= b; ++i)
  {
    res *= 2;
    v.push_back(res);
  }
  n -= b;
  if(v.size() == 1) {
    if(a)
      v.push_back(1), --n;
  }
  for (int i = 0; i < a; ++i)
  {
    v.push_back(v[v.size()-1] + 1);
    --n;
  }
  if(n < 0) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < n; ++i)
  {
    v.push_back(v[v.size() - 1]);
  }
  for(int it: v)
    cout << it << ' ';
  if(v.size() != nn)
    return -1;
  
}