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

int arr[N], pre[N];

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 1; i <= n; ++i) {
		pre[i] += arr[i-1] + pre[i-1];
	}
	string str;
	cin >> str;
	ll mxSum = 0, cur = 0;
	int farestOne = -1, farestOneB = -1;
	for (int i = 0; i < n; ++i) {
		if(str[i] == '1') {
			farestOneB = farestOne;
			farestOne = i;
			mxSum += arr[i];
		}
	}
//
//	cur = 0;
//	for (int i = 0; i < farestOne; ++i)
//		cur += arr[i];
//	mxSum = max(mxSum, cur);
//
//	cur = arr[farestOne];
//	for (int i = 0; i < farestOneB; ++i)
//		cur += arr[i];
//	mxSum = max(mxSum, cur);

	ll total1 = 0;
	cur = 0;
	for (int i = n-1; i >= 0; --i) {
		if(str[i] == '0')
			continue;
		total1 += arr[i];
		cur = pre[i];
		mxSum = max(mxSum, cur + total1 - arr[i]);
	}

	cout << mxSum;
}
