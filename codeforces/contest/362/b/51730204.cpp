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

int const N = 1e5 + 9, M = 100 + 9, OO = 1e9;

unordered_map<int, bool> mp;
vector<int> vec;

int main() {
	cout << fixed << setprecision(12);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, m, a;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a;
		mp[a] = 1;
		vec.push_back(a);
	}
	if(mp[n] || mp[1]) {
		cout << "NO";
		return 0;
	}
	sort(vec.begin(), vec.end());
	for(auto it: vec) {
		if(mp[it+1] && mp[it+2]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
//	int cur = 1;
//	while(cur < n) {
//		if(!mp[cur+1] && cur+1 <= n) {
//			cur = cur + 1;
//		} else if(!mp[cur+2] && cur+2 <= n) {
//			cur = cur + 2;
//		} else if(!mp[cur+3] && cur+3 <= n) {
//			cur = cur + 3;
//		} else {
//			cout << "NO";
//			return 0;
//		}
//	}
//	cout << "YES";
}
