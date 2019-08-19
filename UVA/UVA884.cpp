#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-6, PI = acos(-1);
const int N = 1e6 + 9, OO = 1e9;

ll freq[N];
vector<int> pr;
bool vis[N];

int mx = 1e6 + 1;
void sieve() {
  for (ll i = 2; i * i < mx; ++i) {
    if (vis[i])
      continue;
    for (ll j = i * i; j <= mx; j += i)
      vis[j] = 1;
  }
  for (int i = 2; i < mx; ++i) {
    if(!vis[i])
      pr.push_back(i);
  }
}

int main() {
  fastIO;
  sieve();
//  read;
  for(int it: pr) {
    int cur = it;
    while(cur < mx) {
      int temp = cur;
      while(temp % it == 0) {
        ++freq[cur];
        temp /= it;
      }
      cur += it;
    }
  }
  for (int i = 2; i < mx; ++i)
    freq[i] += freq[i - 1];
  int n;
  while (cin >> n)
    cout << freq[n] << '\n';
  return 0;
}

