#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
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

int const N = 1e4 + 200 + 9, M = 1e6 + 9, OO = 1e9;

ll mem[109][N][3];
int m, n;
vector<pair<int, int>> vec;

ll dp(int i = 0, int total = 0, bool takeit = 0) {
	if(i >= n)
		return 0;
	ll& ret = mem[i][total][takeit];
	if(~ret)
		return ret;
	ret = 0;
	ret = dp(i+1, total);
	if(vec[i].first + total <= m)
		ret = max(ret, dp(i+1, total + vec[i].first, takeit) + vec[i].second);
	if(!takeit&&vec[i].first + (total) > 2000 && vec[i].first + total <= m + 200 )
		ret = max(ret, dp(i+1, total + vec[i].first, 1) + vec[i].second);
	return ret;
}

int main() {
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	while(cin >> m >> n) {
		vec.clear();
		int a, b;
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			vec.push_back({a, b});
		}
		sort(all(vec));
		clr(mem, -1);
		cout << dp() << '\n';
	}
	return 0;
}


