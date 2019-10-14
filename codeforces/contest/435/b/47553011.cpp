#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	string str;
	char cmp;
	ll k, n, j, z, curr;
	bool ok = false;
	cin >> str >> k;
	n = str.length();
	for (ll i = 0; i < n && k > 0; ++i) {
		z = min(k + i+1, (ll)str.length());
		ok = false;
		cmp = str[i];
		for (j = i+1; j < z; ++j) {
			if(str[j] > cmp) {
				curr = j;
				cmp = str[j];
				ok = true;
			}
		}
		if(ok) {
			for (ll k = curr; k > i ; --k) {
				swap(str[k], str[k-1]);
			}
//			swap(str[i], str[curr]);
			k -= curr-i;
		}
	}
	cout << str;
}
