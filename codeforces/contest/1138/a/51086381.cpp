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

int const N = 1e6 + 9, M = 100 + 9, OO = 1e9;

vector<pair<int, int>> vec;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n = 0, a = 0, prv = 0, ans = 0, cnt = 1;
	cin >> n >> a;
	prv = a, cnt = 1;
	for (int i = 1; i < n; ++i) {
		cin >> a;
		if(a == prv) {
			++cnt;
//			vec.push_back({a, cnt});
		} else {
			vec.push_back({prv, cnt});
			cnt = 1;
		}
		prv = a;
	}
	vec.push_back({a, cnt});
//	for(auto it: vec) {
//		cout << it.first << " " << it.second << "\n";
//	}
	ans = 0, n = sz(vec);
	for (int i = 1; i < n; i += 2) {
		cnt = 0;
		if(i+1 < n) {
			cnt = min(vec[i].second, vec[i+1].second);
		}
		cnt = max(cnt, min(vec[i].second, vec[i-1].second));
		ans = max(ans, cnt);
	}
	cout << ans * 2;
	return 0;
}
