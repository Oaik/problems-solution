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
	ll t, k;
	int c = 0;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		c = 0;
		cin >> k;
		cout << "Case #" << i << ": " << k << " = ";
		for (ll j = 2; j*j <= k; ++j)
		{
			if(k % j == 0) {
				cout << j << " * " << k/j;
				++c;
				if(c == 1)
					cout << " = ";
				if(c == 2) {
					cout << '\n';
					break;
				}
			}
		}
	}
  return 0;
}
