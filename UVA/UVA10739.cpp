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

int const N = 1e3 + 9, M = 100 + 9, OO = 1e9;

int dp[N][N];
string str;

int solve(int i, int j) {
	if(i >= j)
		return 0;
	int& ret = dp[i][j];
	if(~ret)
		return ret;
	ret = OO;
	if(str[i] == str[j])
		return ret = solve(i+1, j-1);
	return ret = min(solve(i+1, j-1)+1, min(solve(i+1, j)+1,solve(i, j-1)+1));
}

int main() {
	cout << fixed << setprecision(6);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		clr(dp, -1);
		cin >> str;
		cout << "Case " << i+1 << ": " << solve(0, str.length()-1) <<"\n";
	}
}

