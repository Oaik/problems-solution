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

int const N = 1e4 + 9, M = 100 + 9, OO = 1e9;

int arr[N], n, k;
int dp[N][29][29];

int solve(int i, int l = 0, int r = 0) {
	if (l > k || r > k)
		return 1e9;
	if ( i > (n/2) || l+r > n/2)
		return 0;

	int& ret = dp[i][l][r];
	if (~ret)
		return ret;

	if (arr[i] == arr[n-1-i+r-l])
		return ret = solve(i + 1, l, r);

	return ret = min(solve(i + 1, l, r+1) + 1, solve(i, l+1, r) + 1);
}

int main() {
	cout << fixed << setprecision(6);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	bool can = 0;
	int t, res;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		can = 1;
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		cout << "Case " << i + 1 << ": ";
		// check if the array is Palindrome
		for (int i = 0; i < n / 2; ++i) {
			if (arr[i] != arr[n - 1 - i]) {
				can = 0;
				break;
			}
		}
		if (can) {
			cout << "Too easy\n";
			continue;
		}
		clr(dp, -1);
		res = solve(0, 0, 0);
		if (res > k)
			cout << "Too difficult\n";
		else
			cout << res << "\n";
	}
}

