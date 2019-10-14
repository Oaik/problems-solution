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

int const N = 1e9 + 9, M = 100 + 9, OO = 1e9;

unordered_map<int, bool> mp;
unordered_map<int, int> mpa;

int main() {
	cout << fixed << setprecision(2);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, a;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		mp[a] = 1;
		++mpa[a];
	}
	int mx = 0, cnt = 0;
	for (std::unordered_map<int, bool>::iterator it = mp.begin(); it != mp.end(); ++it) {
		cnt = 0;
		for (int j = it->first; j <= it->first + 5; ++j) {
			if (mpa[j])
				cnt += mpa[j];
		}
		mx = max(cnt, mx);
	}
	cout << mx;
	return 0;
}
