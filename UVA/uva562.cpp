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

int const N = 1e5 + 9, M = 100 + 9, OO = 5e8 + 9;

int n, arr[101], mem[101][50001], total;

int dp(int i = 0, int sum = 0) {
	if(i == n) {
		return abs((total - sum) - sum);
	}
	int& ret = mem[i][sum];
	if(~ret)
		return ret;
	int c1 = dp(i+1, sum);
	int c2 = dp(i+1, sum + arr[i]);
	ret = min(c1, c2);
	return ret;
}

int main() {
	cout << fixed << setprecision(0);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		total = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			total += arr[i];
		}
		clr(mem, -1);
		cout << dp() << "\n";
	}
	return 0;
}

