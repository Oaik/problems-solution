#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v)  	((v).begin()),((v).end())
#define sz(x)  		((ll) (x).size())
#define clr(a,b)	memset(a,b,sizeof(a))
const double EPS = 1e-8;
const double pi = acos(-1);
ll dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
void debug() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "rt", stdin);
//	freopen("output.in", "wt", stdout);
#endif
}

int const N = 2e5 + 9, M = 100 + 9, OO = 1e9;

int arr1[N], arr2[N];
map<pair<int, int>, int> mp;

int main() {
	cout << fixed << setprecision(2);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr1[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> arr2[i];
	}
	int g,a,b, mx = 0, cnt = 0;
	for (int i = 0; i < n; ++i) {
		g = __gcd(arr1[i], arr2[i]);
		if(g == 0) {
			++cnt;
			continue;
		}
		b = arr2[i]/g, a = arr1[i]/g;
		if(a == 0)
			continue;
		if(b == 0) {
			++mp[{0,0}];
			mx = max(mx, mp[{0, 0}]);
		} else {
			++mp[{-b, a}];
			mx = max(mx, mp[{-b, a}]);
		}
	}
	cout << mx + cnt;
	return 0;
}
