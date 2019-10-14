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
	//freopen("output.in", "wt", stdout);
#endif
}

ll const N = 1e5 + 9, M = N*N/2, OO = 1e12 + 9;

vector<pair<ll, int>> vec;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, d, a, b, l, h;
	cin >> n >> d >> a >> b;
	for (int i = 0; i < n; ++i) {
		cin >> l >> h;
		vec.push_back({(a * l) + (b * h), i+1});
	}
	sort(vec.begin(), vec.end());
	int idx = 0;
	bool can = false;
	vector<int> ans;
	while(!can && idx < n) {
		if(vec[idx].first <= d) {
			d -= vec[idx].first;
			ans.push_back(vec[idx].second);
		} else
			break;
		++idx;
	}
	cout << sz(ans) << "\n";
	for(int it: ans)
		cout << it << " ";
	return 0;
}
