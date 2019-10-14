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

int d[N];
vector<vector<int>> vec;

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}
	vec = vector<vector<int>> (n+1);
	char prv = '?', cur;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cin >> cur;
		if(prv == cur) {
			vec[cnt].push_back(d[i]);
		} else {
			++cnt;
			vec[cnt].push_back(d[i]);
		}
		prv = cur;
	}
	int idx = 0;
	ll sum = 0;
	for(int i = 1; i <= cnt; ++i) {
		sort(vec[i].begin(), vec[i].end(), greater<int>());
		idx = 0;
		for(auto itt: vec[i]) {
			if(idx == m)
				break;
			sum += itt;
			++idx;
		}
	}
	cout << sum;
	return 0;
}
