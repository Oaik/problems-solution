#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8, pi = acos(-1);
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "rt", stdin);  //	freopen("output.in", "wt", stdout);
#endif
}

int const N = 2e5 + 9, OO = 1e9;

int arr[N], freq[N], out[N];

vector<int> dup, leftt;

int main() {
  cout << fixed << setprecision(12);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  debug();
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    ++freq[arr[i]];
    if(freq[arr[i]] > 2) {
      cout << "NO";
      return 0;
    } else if(freq[arr[i]] == 2) {
      dup.push_back(arr[i]);
    }
  }
  sort(arr, arr+n);
  for (int i = 0; i < n; ++i) {
    if(out[arr[i]])
      continue;
    leftt.push_back(arr[i]);
    ++out[arr[i]];
  }
  sort(all(leftt));
  sort(all(dup));
  int z = dup.size(), x = leftt.size();
  cout << "YES\n";
  cout << x << "\n";
  for(auto it: leftt)
    cout << it << " ";
  cout << "\n";
  cout << z << "\n";
  for (int i = z-1; i >= 0; --i) {
    cout << dup[i] << " ";
  }
  return 0;
}