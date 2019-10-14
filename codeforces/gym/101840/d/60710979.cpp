#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "rt", stdin);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e5 + 9, M = 1e6 + 1, OO = 1e9 + 1;
const long long MOD = 1e9 + 7;

int par[N], sz[N];
vector<int> adj[N];
int find(int x) {
  if(x == par[x]) return x;
  return par[x] = find(par[x]);
}
bool join(int x, int y) {
  x = find(x), y = find(y);
  if(x == y)
    return 0;
  if(sz[x] < sz[y])
    swap(x, y);
  par[y] = x;
  sz[x] += sz[y];
  return 1;
}
void init() {
  iota(par, par + N, 0);
  fill(sz, sz + N, 1);
  for(int i = 0;i<N;i++){
    adj[i].clear();
  }
}
void divisors(ll n,int idx) {
  ll i;
  for (i = 1; i * i < n; i++) {
    if (n % i == 0) {
      adj[i].push_back(idx);
      adj[n/i].push_back(idx);
    }
  }
  if (i * i == n)
    adj[i].push_back(idx);
}
int main() {
  fastIO
  read("dream.in")
//  read("input.in")
  int T,
  cases = 0;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    init();
    ll mx =0;
    for(int i=0;i<n;i++){
      ll x;
      cin >> x;
      divisors(x,i);
      mx = max(mx,x);
    }
    ll sum = 0;
    for(ll i =mx;i>=1;i--){
      for(int j = 1;j<(int)adj[i].size();j++){
        if(join(adj[i][0],adj[i][j])){
          sum += i;
        }
      }
    }
    cout << "Case " << ++cases << ": " << sum << el;
  }
  return 0;
}
