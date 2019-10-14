#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read freopen("input.in", "rt", stdin);
#define write freopen("output.in", "wt", stdout);
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
double const EPS = 1e-8, PI = acos(-1);
const int N = 2e5 + 9, OO = 1e9;

map<ll, int> freqL, freqR;
int arr[N];

int main() {
  fastIO;
  ll n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    ++freqR[arr[i]];
  }
  ll total = 0;
  for (int i = 0; i < n; ++i) {
    ll k1 = 0, k2 = 0;
    if(arr[i] % k == 0)
      k1 = freqL[arr[i] / k];
    --freqR[arr[i]];
    if(freqR.find(arr[i] * k) != freqR.end())
      k2 = freqR[arr[i] * k];
    ++freqL[arr[i]];
    total += k1 * k2;
  }
  cout << total;
  return 0;
}
