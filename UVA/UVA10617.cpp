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

ll mem[65][65];
string str;

ll dp(int i, int j) {
	if(i == j)
		return 1;
	if(i > j)
		return 0;
	ll& ret = mem[i][j];
	if(~ret)
		return ret;
	ret = 0;
	if(str[i] == str[j])
		return ret = dp(i+1, j) + dp(i, j-1) + 1;
	else
		return ret = dp(i+1, j) + dp(i, j-1) - dp(i+1, j-1);
}

int main() {
	cout << fixed << setprecision(12);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	debug();
	int t;
	cin >> t;
	while(t--) {
		clr(mem, -1);
		cin >> str;
		cout << dp(0, str.length()-1) << '\n';
	}
	return 0;
}

