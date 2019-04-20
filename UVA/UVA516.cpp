#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define all(v)    ((v).begin()),((v).end())
#define clr(a,b)  memset(a,b,sizeof(a))
void debug() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
freopen("output.txt", "wt", stdout);
#endif
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

int const N = 2e9 + 9, OO = 1e9;

unordered_map<int, int> mp;
set<int, greater<int>> s;

ll num;
void factorize() {
  mp.clear();
  s.clear();
  for (ll i = 2; i * i <= num; ++i) {
    while(num % i == 0) {
      num /= i;
      ++mp[i];
      s.insert(i);
    }
  }
  if(num > 1)
    s.insert(num), ++mp[num];
}

int main() {
  bool f = 0, x = 0;
  debug();
  string str;
  while (getline(cin, str), str[0] != '0') {
    f = 1;
    num = 1;
    stringstream ss(str);
    string ss1, ss2;
    while (ss >> ss1) {
      ss >> ss2;
      num *= pow(stoi(ss1), stoi(ss2));
    }
    --num;
    factorize();
    cout << *s.begin() << " " << mp[*s.begin()];
    x = 0;
    for(auto it: s) {
    	if(!x) {
    		x = 1;
    		continue;
    	}
      cout << " " << it << " " << mp[it];
    }
  	cout << '\n';
  }
  return 0;
}

