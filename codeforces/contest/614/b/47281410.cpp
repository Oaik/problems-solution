#include <bits/stdc++.h>

using namespace std;
#define ll long long

int arr[101];

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	ll n, rem, cnt = 0, sz, curr = 0;
	string a, c, res;
	bool foundOne = false;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		foundOne = false, curr = 0;
		cin >> a;
		if(a == "0") {
			cout << 0;
			return 0;
		}
		c = a;
		sz = a.length();
		for(int i = 0; i < sz; ++i) {
			rem = a[sz-i-1] - '0';
			if(foundOne == true || (rem != 0 && rem != 1)) {
				res = c;
				cnt -= curr;
				break;
			}
			if(rem == 1)
				foundOne = true;
			else ++cnt, ++curr;
		}
	}
	if(!res.empty())
		cout << res;
	else
		cout << "1";
	for (int i = 0; i < cnt; ++i) {
		cout << 0;
	}
}
