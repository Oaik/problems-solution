#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	ll n;
	ll j = 0;
	string str;
	cin >> n >> str;
	for (ll i = 0; i < n; ++i) {
		cout << str[i];
		i += j;
		j++;
	}
}
