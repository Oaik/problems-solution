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

int main() {
  debug();
  ll n, temp, count, res, nn;
  while(cin >> n, n) {
  	count = 0, res = 1,nn = n;
  	n = abs(n);
  	for (ll i = 2; i*i <= (ll)n; ++i)
  	{
  		temp = n, count = 0;
  		while(temp % i == 0) {
  			temp /= i;
  			++count;
  		}
  		if(temp == 1) {
  			if((nn > 0) || (nn < 0 && count % 2 != 0))
  			res = max(res, count);
  		}
  		count = 0;
  	}
  	cout << res << endl;
  }
  return 0;
}
