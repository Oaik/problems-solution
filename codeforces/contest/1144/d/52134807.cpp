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

int arr[N], freq[N];

vector<pair<int, pair<int, int>>> vv;

bool vis[N];

int main() {
  cout << fixed << setprecision(12);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  debug();
  int n, best = 0, nums = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    ++freq[arr[i]];
    if(freq[arr[i]] > best) {
      best = freq[arr[i]];
      nums = arr[i];
    }
  }
//  cout << best << " " << nums << " " <<  idx;
  int lps = n - best;
  cout << lps << '\n';
  if(lps == 0)
    return 0;
  int lf = 1e9, ri = 0;
  for (int i = 0; i < n; ++i) {
    if(arr[i] == nums) {
      if(i+1 < n) {
        if(arr[i+1] > arr[i]) {
          cout << "2 " << i+2 << " " << i+1 << '\n';
        } else if(arr[i+1] < arr[i]) {
          cout << "1 " << i+2 << " " << i+1 << '\n';
        }
        arr[i+1] = nums;
        ri = max(ri, i+1);
      }
    }
  }
  for (int i = ri+1; i < n; ++i) {
    if(arr[i] == nums)
      continue;
    if(arr[i] > nums) {
      cout << "2 " << i+2 << " " << i+1 << '\n';
    } else {
      cout << "1 " << i+2 << " " << i+1 << '\n';
    }
    arr[i] = nums;
  }
  for (int i = ri-1; i >= 0; --i) {
    if(arr[i] == nums)
      continue;
    if(arr[i] > nums) {
      cout << "2 " << i+1 << " " << i+2 << '\n';
    } else {
      cout << "1 " << i+1 << " " << i+2 << '\n';
    }
    arr[i] = nums;
  }
  return 0;
}