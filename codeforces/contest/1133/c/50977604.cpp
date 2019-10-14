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

map<int, int> mp;
vector<int> vec;

int main() {
	cout << fixed << setprecision(2);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, a;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		++mp[a];
		vec.push_back(a);
	}
	int mx = 0, cnt = 0;
	for (auto it: vec) {
		cnt = 0;
		for (int j = it; j <= it+5; ++j) {
			if(mp[j])
				cnt += mp[j];
		}
		mx = max(cnt, mx);
	}
	cout << mx;
	return 0;
}