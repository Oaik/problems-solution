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

vector<int> prefix(string pat) {
  int m = pat.size();
  vector<int> table(m, 0);
  for (int i = 1, k = 0; i < m; ++i) {
    while(k > 0 && pat[i] != pat[k])
      k = table[k-1];
    if(pat[i] == pat[k])
      table[i] = ++k;
    else
      table[i] = k;
  }
  return table;
}

void kmp(string text, string pat) {
  int n = text.size(), m = pat.size();
  vector<int> preTable = prefix(pat);
  for (int i = 0, k = 0; i < n; ++i) {
    while(k > 0 && pat[k] != text[i])
      k = preTable[k-1];
    if(text[i] == pat[k])
      ++k;
    if(k == m){
      cout << i - m + 1 << '\n';
      k = preTable[k-1];
    }
  }
}

int main() {
  fastIO;
//  read("input.in");
//  write("input.in");
  int t;
  while(cin >> t) {
    string text, pat;
    cin >> pat >> text;
    kmp(text, pat);
//    cout << '\n';
    cout << endl;
  }
  return 0;
}

