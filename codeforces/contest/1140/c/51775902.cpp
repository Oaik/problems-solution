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

int const N = 3e5 + 9, M = 100 + 9, OO = 1e9;

pair<ll, ll> arr[N];
multiset<ll> s;

int main() {
	cout << fixed << setprecision(12);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n, k;
	cin >> n >> k;
	for (int u = 0; u < n; ++u) {
		cin >> arr[u].second >> arr[u].first;
	}
	sort(arr, arr+n);
	ll ans = 0, sum = 0;
	for (int i = n-1; i >= 0; --i) {
		sum += arr[i].second;
		s.insert(arr[i].second);
		if(s.size() > k) {
			sum -= *s.begin();
			s.erase(s.begin());
		}
		ans = max(ans, sum * arr[i].first);
	}
	cout << ans;
	return 0;
}
