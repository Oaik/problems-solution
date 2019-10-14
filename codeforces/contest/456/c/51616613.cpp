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

int arr[N];
map<int, ll> mp;
int n, a, mxNum;

ll dp[N];
ll solve(int i) {
	if(i > mxNum)
		return 0;
	ll& ret = dp[i];
	if(~ret)
		return ret;
	ret = solve(i+1);

	ret = max(ret, solve(i+2) + mp[i]);
	return ret;
}

int main() {
	cout << fixed << setprecision(12);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	cin >> n;
	mxNum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		arr[i] = a;
		mxNum = max(mxNum, a);
	}
	sort(arr, arr + n);
	int prv = arr[0];
	ll cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (prv == arr[i]) {
			cnt += prv;
		} else {
			mp[prv] = cnt;
			cnt = arr[i];
		}
		prv = arr[i];
	}
	mp[prv] = cnt;
	clr(dp, -1);
	cout << solve(1);
}
