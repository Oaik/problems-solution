#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
#define all(v) ((v).begin()),((v).end())
#define read(v) freopen(v, "r", stdin)
#define write(v) freopen(v, "wt", stdout)
#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 2e5 + 9, M = 2e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

int arr[N];

vector<int> prefixF(string pat) {
  int m = pat.size();
  vector<int> table(m, 0);
  for (int i = 1, k = 0; i < m; ++i) {
    while(k > 0 && pat[i] != pat[k])
      k = table[k-1];
    if(pat[k] == pat[i])
      table[i] = ++k;
    else
      table[i] = k;
  }
  return table;
}

bool kmp(string text, string pat) {
  int n = text.size(), m = pat.size();
  vector<int> prefix = prefixF(pat);
  for (int i = 0, k = 0; i < n; ++i) {
    while(k > 0 && pat[k] != text[i])
      k = prefix[k-1];
    if(pat[k] == text[i])
      ++k;
    if(k == m)
      return 1;
  }
  return 0;
}

int main() {
  fastIO;
//  read("input.in");
//  write("input.in");
  int t, n,a ,prv;
  cin >> t;
  while(t--) {
    cin >> n;
    string text, pat;
    for (int i = 0; i < n; ++i) {
      cin >> a;
      if(i) {
        if(a > prv)
          text.push_back('G');
        else if(a == prv)
          text.push_back('E');
        else
          text.push_back('L');
      }
      prv = a;
    }
    cin >> pat;
    if(kmp(text, pat))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}

