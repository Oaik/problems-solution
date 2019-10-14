#include <bits/stdc++.h>

using namespace std;
#define ll long long

map<int, int> mp1;
map<int, int> mp2;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, x, y, ans = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		if(mp1[x+y])
			ans += mp1[x+y];
		if(mp2[y-x])
			ans += mp2[y-x];
//		if(x != 1 || y != 1)
		mp1[x+y]++;
		mp2[y-x]++;
	}
	cout << ans;
    return 0;
}
