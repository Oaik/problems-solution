#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(),x.end()

const double EPS = 1e-8;
int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}

map<int, int> mp;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
	int from, to, h, i = 0, mxTo = 0;
	while(cin >> from >> h >> to) {
		mxTo = max(mxTo, to);
		for ( i = from; i < to; ++i)
			mp[i] = max(h, mp[i]);
	}
	cout << mp.begin()->first << " " << mp.begin()->second;
	for (i = (mp.begin()->first)+1; i <= mxTo; ++i) {
		if(mp[i] != mp[i-1]) {
			cout << " " << i << " " << mp[i];
		}
	}
	cout << "\n";
	return 0;
}
